#include "Manipulator.h"
#include <algorithm>

// Convert ciphertext data of character pointers to a vector of vectors of char pointers to words, ordered by length of word 
std::vector<std::vector<char*>> groupData(const std::vector<char*>& data)
{
	std::vector<std::vector<char*>> wordGroups;

	for (auto it = data.cbegin(); it != data.cend(); ++it)
	{
		char* c;
		for (c = *it; *c != NULL && isalpha(*c); ++c);
		size_t len = c - *it;
		while (wordGroups.size() < len)
			wordGroups.emplace_back();
		wordGroups[len - 1].push_back(*it);
	}

	return wordGroups;
}