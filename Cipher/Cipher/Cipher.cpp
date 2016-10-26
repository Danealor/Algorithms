#include "Cipher.h"

void decrypt(std::vector<char*>& words, const size_t& wordLength)
{
	if (words.size() == 0) return;

	std::vector<std::vector<bool>> swapFlags(words.size());
	for (auto v : swapFlags)
		v.reserve(wordLength);

	for (int i = 0; i < words.size(); ++i)
	{
		size_t i_swap = i;
		size_t j_swap = 0;
		bool reverse = false;
		for (int j = 0; j < wordLength; ++j)
		{
			if (swapFlags[i][j]) continue;

			while (swapFlags[i_swap][j_swap] || (i == i_swap && j == j_swap))
			{
				if (++i_swap >= words.size())
				{
					if (reverse) break;
					i_swap = i;
					reverse = true;
				}

				if (reverse)
					for (j_swap = wordLength - 1; j_swap >= 0 && (swapFlags[i_swap][j_swap] || (i == i_swap && j == j_swap)); --j_swap);
				else
					for (j_swap = 0; j_swap < wordLength && (swapFlags[i_swap][j_swap] || (i == i_swap && j == j_swap)); ++j_swap);
			}

			if (swapFlags[i_swap][j_swap]) continue;

			char temp = words[i][j];
			words[i][j] = words[i_swap][j_swap];
			words[i_swap][j_swap] = temp;

			swapFlags[i][j] = true;
			swapFlags[i_swap][j_swap] = true;
		}
	}
}