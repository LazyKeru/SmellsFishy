#include <iostream>
#include "../../header/test/test.hpp"

int main(int argc, const char* argv[])
{
	std::cout << "Starting test...\n";
	for (size_t i = 0; i < argc; i++)
	{
		std::string s(argv[i]);

		if (s == "all") {
			std::cout << "Testing all...\n";
			test::regex();
			test::fileToString();

			return 0;
		}
		else if (s == "regex") {
			std::cout << "Testing regex...\n";
			test::regex();
		}
		else if (s == "entropy") {
			std::cout << "Testing entropy...\n";
			
		}
		else if (s == "file_read") {
			std::cout << "Testing file_read...\n";
			test::fileToString();
		}
	}
}