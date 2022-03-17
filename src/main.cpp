#include <iostream>
#include "../header/regex/regex.hpp"
#include "../header/files/readDir.hpp"
#include <vector>

int main(int argc, char const *argv[])
{
    auto path = "C:/Users/Eloi/Desktop/Projets/SmellsFishy/SmellsFishy";
    if (isDir(path));

    auto v = readDirRecursive(path, true);

    for(const auto& s : v)
        std::cout << s << " : "<< isDir(s) << std::endl;
    
    return 0;
}
