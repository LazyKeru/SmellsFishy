#pragma once
/************************/
/**      Includes      **/
/************************/
#include <vector>
#include <string>

namespace Files
{
	/**
	 * @brief returns true if the path is a directory
	 */
	bool isDir(const std::string& dirPath);

	/**
	 * @brief returns all the paths inside a directory
	 * @return std::vector<std::string> an array containing all the complete path to files inside the directory.
	 * CAN RETURN PATH TO OTHER DIRECTORIES
	 */
	std::vector<std::string> readDir(const std::string& dirPath);

	/**
	 * @brief returns all the files inside a directory and its subdirectories
	 * @param bool includeDirectories should it return the path to directories aswell
	 * @return std::vector<std::string> an array conataining all the files (not directories) inside the dir and
	 * its subdirs
	 */
	std::vector<std::string> readDirRecursive(const std::string& dirPath, bool includeDirectories = false);
	/**
	 * @brief Checks if the file is json
	 * 
	 * @param jsonPath
	 * @return true 
	 * @return false 
	 */
	bool isJson(const std::string &jsonPath);
}