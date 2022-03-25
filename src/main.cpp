#include <iostream>
#include "../header/util/argument.hpp"
#include "../header/util/line_parser.hpp"
#include "../header/files/readDir.hpp"
#include "../header/core/core.hpp"
#include <vector>

/**
 * @brief 
 * 
 * @example `main.exe -h`
 */
const int HELP_I = 0;
Argument _help(false, (std::string) "--help", (std::string) "-h");
/**
 * @brief 
 * 
 */
const int DIR_I = 1;
Argument _dir(true, (std::string) "--dir", (std::string) "-d");
const int RULES_I = 2;
Argument _rules(true, (std::string) "--rules", (std::string) "-r");
std::vector<Argument> _Arguments = {
    _help,
    _dir,
    _rules
};



int main(int argc, char *argv[])
{
    Line_parser::check_arguments(&_Arguments, argv, argc);
    if(!Line_parser::ammountArguments(&_Arguments,argc)){
        // Not enough or too much arguments
        Core::warning();
        Core::help();
        return 0;
    }
    if(_Arguments[HELP_I].defined){
        // Will call the help function
        Core::help();
        return 0;
    }
    if(!_Arguments[DIR_I].defined){
        // Missing arg error
        Core::warning();
        Core::help();
        return 0;
    }
    if(!_Arguments[RULES_I].defined){
        // Missing arg error
        Core::warning();
        Core::help();
        return 0;
    }
    if(!Files::isDir(_Arguments[DIR_I].value)){
        // Missing arg error
        Core::warning();
        Core::help();
        return 0;
    }
    if(!Files::isDir(_Arguments[RULES_I].value)){
        // Missing arg error
        Core::warning();
        Core::help();
        return 0;
    }
    if(_Arguments[DIR_I].defined && _Arguments[RULES_I].defined){
        // Missing arg error
        return 0;
    }
    return 0;
}
