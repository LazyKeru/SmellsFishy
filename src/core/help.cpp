#include "../../header/core/core.hpp"

void Core::help(){
    usage();
    std::cout 
        << "  > --dir/-d : path for the analyzed directory\n"
        << "  > --rules/-r : path for the rules to follow\n"
        << "  > --help/-h : help\n";
    return;
}

void Core::usage(){
    std::cout 
        << "usage: \n"
        << "main.exe [--help/-h] [--dir/-d <path>] [--rules/-r <path>]\n";
    return;
}

void Core::warning(){
    std::cout 
        << "Wrong usage of the executable\n";
    return;
}