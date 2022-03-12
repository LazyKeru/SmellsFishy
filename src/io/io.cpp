#include "../../header/io/io.h"
#include <sstream>
#include <fstream>
#include "../../header/util/util.h"

std::string io::fileToString(const std::string& filePath)
{
	std::ifstream file;
	file.open(filePath);
	util::assertCondition(!file.fail());
	std::ostringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}
