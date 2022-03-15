#include <iostream>
#include "../../header/test/test.hpp"

int main(int argc, const char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		std::string s(argv[i]);

		if (s == "all") {
			test::regex();
			test::fileToString();

			return 0;
		}
		else if (s == "regex") {
			test::regex();
		}
		else if (s == "entropy") {
			
		}
		else if (s == "file_read") {
			test::fileToString();
		}
	}
}