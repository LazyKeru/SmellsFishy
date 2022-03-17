#include <filesystem>
#include "../../header/files/readDir.hpp"

namespace fs = std::filesystem;

bool Files::isDir(const std::string &dirPath)
{
    return fs::is_directory(dirPath);
}

std::vector<std::string> Files::readDir(const std::string &dirPath)
{
    std::vector<std::string> r;
    for (const auto &entry : fs::directory_iterator(dirPath))
        r.push_back(entry.path().string());

    return r;
}

std::vector<std::string> Files::readDirRecursive(const std::string &dirPath, bool includeDirectories)
{
    std::vector<std::string> r;

    for (const auto &entry : fs::recursive_directory_iterator(dirPath))
        if (includeDirectories)
            r.push_back(entry.path().string());
        else if (!fs::is_directory(entry))
            r.push_back(entry.path().string());

    return r;
}
