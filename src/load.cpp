#include "load.hpp"
#include <fstream>
#include <iostream>
#include <cstdint>

void reverseInt(int& i) {
    unsigned char c1, c2, c3, c4;
    c1 = i         & 255;
    c2 = (i >> 8)  & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;
    i =  ((int)c1 << 24) | ((int)c2 << 16) | ((int)c3 << 8) | c4;
}

std::vector<std::vector<float>> loadData(std::string path){
	std::ifstream file(path,std::ios::binary);
	if (!file.is_open()){
		std::cerr << "Error: Data path could not be opened" << std::endl; 
		return {};
	}
	int magicNumber,
		items,
		rows,
		columns;
	file.read((char*)&magicNumber, 4);
	file.read((char*)&items, 4);
	file.read((char*)&rows, 4);
	file.read((char*)&columns, 4);
	reverseInt(magicNumber);
	reverseInt(items);
	reverseInt(rows);
	reverseInt(columns);

	if(magicNumber != 0x00000803){
		std::cerr << "Data has been corrupted." << std::endl;
		return {};
	}
	int size = rows * columns;
	std::vector<std::vector<float>> data(items,std::vector<float>(size));
	std::vector<uint8_t> buffer(size);

	for (int i = 0; i < items; i++){
		file.read((char*)buffer.data(), size);
		for (int j = 0; j < size; j++){
			data[i][j] = static_cast<float>(buffer[j])/255.0;
		}
	}

	file.close();
	return data;
}

std::vector<int> loadLabels(std::string path){
	std::ifstream file(path,std::ios::binary);
	if (!file.is_open()){
		std::cerr << "Error: Data path could not be opened" << std::endl; 
		return {};
	}

	int magicNumber,
		items;
	file.read((char*)&magicNumber,4);
	file.read((char*)&items,4);
	reverseInt(magicNumber);
	reverseInt(items);

	std::vector<int> labels(items);
	std::vector<uint8_t> buffer(items);
	if (magicNumber != 0x00000801){
		std::cerr << "Data has been corrupted." << std::endl;
		return {};
	}
	file.read((char*)buffer.data(), items);
	for (int i = 0; i < items; i++) {
		labels[i] = static_cast<int>(buffer[i]);
	}	
	file.close();
	return labels;
}
