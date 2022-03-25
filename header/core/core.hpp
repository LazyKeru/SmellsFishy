#pragma once
/************************/
/**      Includes      **/
/************************/
#include "../../header/util/log.hpp"
#include "../header/files/readDir.hpp"
#include "../header/files/fileToString.hpp"
#include <iostream>
INIT_LOG

namespace Core
{
    void help();
    void usage();
    void warning();
    void analyze(std::string dir, std::string rules);
} // namespace Core
