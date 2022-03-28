#include "../../header/core/core.hpp"


INIT_LOG

void Core::analyze(std::string dir, std::string rules){
    /*-------------------------------------------*/
    /**  Check if dir and rules are directory   **/
    /*-------------------------------------------*/
    if(!Files::isDir(dir)){
        Log::err << "Dir doesn't exist\n";
    }
    if(!Files::isDir(rules)){
        Log::err << "Dir doesn't exist\n";
    }
    std::vector<std::string> _filesPath = Files::readDirRecursive(dir);
}