#include "../../header/core/core.hpp"

INIT_LOG

const int HELP_I = 0;
const int DIR_I = 1;
const int RULES_I = 2;
const int ENTROPY_I = 3;
const int LOG_I = 4;
static std::vector<Argument> _Arguments = {
    {
        false,
        (std::string) "--help",
        (std::string) "-h"
    },
    {
        true,
        (std::string) "--dir",
        (std::string) "-d"
    },
    {
        true,
        (std::string) "--rules",
        (std::string) "-r"
    },
    {
        false,
        (std::string) "--entropy",
        (std::string) "-e"
    },
    {
        true,
        (std::string) "--log",
        (std::string) "-l"
    }
};

void Core::arg(int argc, char *argv[]){
    Line_parser::check_arguments(&_Arguments, argv, argc);
    if(!Line_parser::ammountArguments(&_Arguments,argc)){
        // Not enough or too much arguments
        Log::warn << "Wrong usage of the executable";
        help();
        return;
    }
    if(_Arguments[HELP_I].defined){
        // Will call the help function
        help();
        return;
    }
    if(!_Arguments[DIR_I].defined){
        // Missing arg error
        Log::warn << "Missing the directory argument";
        help();
        return;
    }
    if(!_Arguments[RULES_I].defined){
        // Missing arg error
        Log::warn << "Missing the rules argument";
        help();
        return;
    }
    if(!Files::isDir(_Arguments[DIR_I].value)){
        // Missing arg error
        Log::warn << "Dir is not a directory";
        help();
        return;
    }
    /** NEED TO ADD A CHECK FOR JSON EXTENSION **/
    // if(!Files::isDir(_Arguments[RULES_I].value)){
    //     // Missing arg error
    //     Core::warning();
    //     Core::help();
    //     return;
    // }
    if(_Arguments[DIR_I].defined && _Arguments[RULES_I].defined){
        analyze(_Arguments[DIR_I], _Arguments[RULES_I], _Arguments[ENTROPY_I]);
        if(_Arguments[LOG_I].defined){
            log_output(_Arguments[LOG_I]);
        }
        return;
    }
    return;
}