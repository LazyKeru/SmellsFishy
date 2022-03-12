#include <iostream>
#include "../header/test/test.h"

int main(int argc, const char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		std::string s(argv[i]);

		if (s == "all") {
			test::regex_test();
			test::io_test();

			return 0;
		}
		else if (s == "regex") {
			test::regex_test();
		}
		else if (s == "entropy") {
			
		}
		else if (s == "file_read") {
			test::io_test();
		}
	}
}