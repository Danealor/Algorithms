#include "Manipulator.h"

// Convert ciphertext data of character pointers to one-word strings
std::vector<std::string> PointersToStrings(const std::vector<char*>& data)
{
	std::vector<std::string> stringList;

	for (auto it = data.cbegin(); it != data.cend(); ++it)
	{
		char* c;
		for (c = *it; *c != NULL && isalpha(*c); ++c);
		stringList.emplace_back(*it, c - *it);
	}

	return stringList;
}