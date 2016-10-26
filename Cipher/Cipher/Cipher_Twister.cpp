#include "Cipher_Twister.h"
#include <random>
#include <stack>
#include <vector>
#include <iostream>

void decrypt(std::vector<char*>& words, const size_t& wordLength, const unsigned int seed)
{
	std::mt19937 rand(seed);

	for (size_t i = 0; i < words.size(); ++i)
	{
		for (size_t j = 0; j < wordLength; ++j)
		{
			size_t i_swap = i;
			size_t j_swap = j;
			while (i_swap == i && j_swap == j)
			{
				i_swap = rand() % words.size();
				j_swap = rand() % wordLength;
			}
			char temp = words[i][j];
			words[i][j] = words[i_swap][j_swap];
			words[i_swap][j_swap] = temp;
		}
	}
}

void encrypt(std::vector<char*>& words, const size_t& wordLength, const unsigned int seed)
{
	std::mt19937 rand(seed);
	std::stack<std::pair<size_t, size_t>> swapList;

	for (size_t i = 0; i < words.size(); ++i)
	{
		for (size_t j = 0; j < wordLength; ++j)
		{
			size_t i_swap = i;
			size_t j_swap = j;
			while (i_swap == i && j_swap == j)
			{
				i_swap = rand() % words.size();
				j_swap = rand() % wordLength;
			}
			swapList.emplace(i_swap, j_swap);
		}
	}

	for (size_t i = words.size(); i > 0; --i)
	{
		for (size_t j = wordLength; j > 0; --j)
		{
			auto pair = swapList.top();
			swapList.pop();

			size_t i_swap = pair.first;
			size_t j_swap = pair.second;

			char temp = words[i - 1][j - 1];
			words[i - 1][j - 1] = words[i_swap][j_swap];
			words[i_swap][j_swap] = temp;
		}
	}
}