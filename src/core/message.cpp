#include "../../header/core/core.hpp"

void Core::help(){
    usage();
    std::cout 
        << "  > --help/-h : help\n"
        << "  > --dir/-d : path for the analyzed directory\n"
        << "  > --rules/-r : path for the rules to follow\n"
        << "  > --entropy/-e : activates the entropy rule\n"
        << "  > --log/-l : path for the log\n";
    return;
}

void Core::usage(){
    std::cout 
        << "usage: \n"
        << "main.exe [--help/-h] [--dir/-d <path>] [--rules/-r <path>] [--entropy/-e] [--log/-l <path>]\n";
    return;
}