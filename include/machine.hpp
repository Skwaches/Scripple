#pragma once
#include <vector>
#include <string>
void train(
		std::initializer_list<int> arrangement,
		std::vector<std::vector<float>> data,
		std::vector<int> labels,
		std::string folder,
		int ep0ch);

void test(
		std::vector<std::vector<float>> data,
		std::vector<int> labels, 
		std::vector<std::vector<float>> trainingData,
		std::vector<int> trainingLabels, 
		std::string folder, 
		int ep0ch
		);
