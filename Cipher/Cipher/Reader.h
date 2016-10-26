#pragma once
#include <string>
#include <fstream>
#include <vector>

class Reader
{
private:
	std::ifstream file;
	char* ciphertext;
public:
	Reader(const std::string& filePath);
	~Reader();

	int getLength();

	std::vector<char*> getData();
	char* getText();
};