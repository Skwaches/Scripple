#include "machine.hpp"
#include <think.hpp>
#include <format>
#include <time.h>

void train(
		std::initializer_list<int> arrangement,
		std::vector<std::vector<float>> data,
		std::vector<int> labels,
		std::string folder,
		int ep0ch
		){
	Network net(arrangement, folder + "/epoch-0.bin");
	for (int epoch = 1; epoch <= ep0ch; epoch++){
		net.path =  folder + std::format("/epoch-{}.bin", epoch);
		time_t start, end;
		std::cout << "Epoch " << epoch << std::endl;
		std::cout << "Training has started.\n";
		time(&start);
		float loss = net.train(data, labels, 0.1, 32);
		time(&end);
		std::cout << "Time Taken: " << difftime(end, start) << " Seconds" <<std::endl;
		std::cout << "New loss: " << loss << std::endl;
		std::cout << "\n\n"; 
	}

}

// Returns the index of the highest value.
int highest(std::vector<float> list){
	int highest = 0;
	for (size_t i = 1; i < list.size(); i++)
		highest = (list[highest] < list[i]) ? i : highest;
	return highest;
}

float test(Network& net, std::vector<std::vector<float>> data, std::vector<int> labels){
	int correct = 0;
	for (size_t i = 0; i < data.size(); i++){
		Matrix guess = net.evaluate(data[i]);
		if ( labels[i] == highest(guess.data)) correct++;
	}
	return (float)correct/data.size() * 100.0;
}

void test(
		std::vector<std::vector<float>> data,
		std::vector<int> labels, 
		std::vector<std::vector<float>> trainingData,
		std::vector<int> trainingLabels, 
		std::string folder, 
		int ep0ch
		){

	float rate;
	for (int epoch = 0; epoch <= ep0ch; epoch++){
		Network net(folder + std::format("/epoch-{}.bin", epoch));
		std::cout << "Epoch " << epoch << std::endl;

		rate = test(net, data, labels);
		std::cout << "Performance: " << rate << "% On the testing set." << std::endl; 

		rate = test(net, trainingData, trainingLabels);
		std::cout << "Performance: " << rate << "% On the training set." << std::endl; 

		std::cout << "\n\n";
	}
}



