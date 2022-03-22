#pragma once
#include <string>

namespace Files
{
    /**
     * @brief returns the file as a string
     * @return std::string 
     * @example fileToString("./SomeFile.c") returns all its text in a string element
     */
    std::string fileToString(const std::string &filePath);
}
