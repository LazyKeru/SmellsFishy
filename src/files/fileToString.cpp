#include "../../header/files/fileToString.hpp"
#include <sstream>
#include <fstream>
#include "../../header/util/util.hpp"


std::string Files::fileToString(const std::string& filePath)
{
	std::ifstream file;
	file.open(filePath);
	myAssert(!file.fail(),"Failed to open the file");
	std::ostringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}
