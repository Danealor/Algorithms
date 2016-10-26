#include "Main.h"
#include "Reader.h"
#include "Manipulator.h"
#include "Cipher.h"
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::string filename(argv[0]);
		Reader reader(filename);

		auto data = reader.getData();
		auto groupedData = groupData(data);
		for (int i = 0; i < groupedData.size(); ++i)
			decrypt(groupedData[i], i + 1);

		std::cout << reader.getText() << std::endl;
	}
	return 0;
}
