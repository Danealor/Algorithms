#include "Reader.h"

Reader::Reader(const std::string& filePath)
{
	file.open(filePath);
}

Reader::~Reader()
{
	file.close();
	delete[] ciphertext;
}

// Returns length of file
int Reader::GetLength()
{
	file.seekg(0, file.end);
	int length = file.tellg();
	file.seekg(0, file.beg);

	return length;
}

// Returns ciphertext data from file as a vector of pointers to the first character of each word in the text.
std::vector<char*> Reader::GetData()
{
	std::vector<char*> data;
	int length = GetLength();

	// Careful of the new keyword!
	ciphertext = new char[length];

	file.read(ciphertext, length);

	bool alpha = false;
	for (char* it = ciphertext; *it != NULL; ++it)
	{
		if (!isalpha(*it))
			alpha = false;
		else if (!alpha)
		{
			data.push_back(it);
			alpha = false;
		}
	}

	return data;
}

char* Reader::GetText()
{
	return ciphertext;
}
