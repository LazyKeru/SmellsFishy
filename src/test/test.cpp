#include <iostream>
#include "../../header/test/test.hpp"

void test::log(const std::string &message, const std::string &filePath, logType log_type)
{
	if (!filePath.empty())
	{
		auto start = filePath.find_last_of('/') + 1, end = filePath.size();
		std::string fileName;
		if (end > start)
		{
			auto fileName = filePath.substr(start, end - start);
			std::cerr << '[' << fileName << "] ";
		}
	}
	if (log_type == logType::error)
		std::cerr << "<<< ERROR >>> \t";
	else if (log_type == logType::warning)
		std::cerr << " < Warning >  \t";
	else if (log_type == logType::message)
		std::cerr << "   Message:   \t";

	std::cerr << message << std::endl;
}

int main(int argc, const char *argv[])
{
	test::log("Starting test...");
	for (size_t i = 0; i < argc; i++)
	{
		std::string s(argv[i]);

		if (s == "all")
		{
			test::log("Testing all...");
			test::regex();
			test::files();

			return 0;
		}
		else if (s == "regex")
		{
			test::log("Testing regex...");;
			test::regex();
		}
		else if (s == "entropy")
		{
			test::log("Testing entropy...\n");
		}
		else if (s == "files")
		{
			test::log("Testing file_read...\n");
			test::files();
		}
	}
}
