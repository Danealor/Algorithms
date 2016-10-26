#pragma once
#include <vector>

void decrypt(std::vector<char*>& words, const size_t& wordLength, const unsigned int seed);
void encrypt(std::vector<char*>& words, const size_t& wordLength, const unsigned int seed);