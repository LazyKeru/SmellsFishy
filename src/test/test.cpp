#include "../../header/test/test.hpp"
#include <iostream>

INIT_LOG

int main(int argc, const char *argv[])
{
	Log::msg << "Starting test...\n";
	for (auto i = 0; i < argc; i++)
	{
		std::string s(argv[i]);
		if (s == "core" || s == "all")
		{
			Log::msg << "Testing core...\n";
			test::core();
		}
		if (s == "regex" || s == "all")
		{
			Log::msg << "Testing regex...\n";
			test::regex();
		}
		if (s == "files" || s == "all")
		{
			Log::msg << "Testing file_read...\n";
			test::files();
		}
		if (s == "entropy" || s == "all")
		{
			Log::msg << "Testing entropy...\n";
			bool res = test::entropy();
			if (res == false)
			{
				Log::err << "Entropy function seems to be broken";
				throw;
				// Safeguard
				return -1;
			}
			Log::msg << "Entropy is working";
		}
		if (s == "struct" || s == "all")
		{
			Log::msg << "Testing struct...\n";
			bool res = test::structure();
			if (res == false)
			{
				Log::msg << "struct functions seems to be broken";
				throw;
				// Safeguard
				return -1;
			}
			Log::msg << "Structures is working";
		}
		if (s == "all"){
			Log::msg << "All is working fine";
			break;
		}
	}
}
