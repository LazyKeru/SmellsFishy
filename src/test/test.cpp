#include "../../header/test/test.hpp"
#include <iostream>

int main(int argc, const char* argv[])
{
	std::cout << "Starting test...\n";
	for (size_t i = 0; i < argc; i++)
	{
		std::string s(argv[i]);

		if (s == "regex" || s == "all") {
			std::cout << "[Regex] Log: Testing regex...\n";
			test::regex();
		}
		if (s == "file_read" || s == "all") {
			std::cout << "[File Read] Log: Testing file_read...\n";
			test::fileToString();
		}
		if (s == "entropy" || s == "all") {
			std::cout << "[Entropy] Log: Testing entropy...\n";
			bool res = test::entropy();
			if(res==false){
				std::cout << "[Entropy] Error: Entropy function seems to be broken";
				throw;
				// Safeguard
				return -1;
			}
			std::cout << "[Entropy] Log: Entropy is working";
		}
		if (s == "struct" || s == "all") {
			std::cout << "[Structure] Log: Testing struct...\n";
			bool res = test::structure();
			if(res==false){
				std::cout << "[Structure] Error: struct functions seems to be broken";
				throw;
				// Safeguard
				return -1;
			}
			std::cout << "[Structure] Log: Structures is working";
		}
	}
}