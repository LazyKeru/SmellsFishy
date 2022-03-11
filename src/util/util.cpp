#include "../../header/util/util.hpp"
#include <iostream>

void _myAssert(const char* expected_expression, const char* error_message, bool condition, const char* file, int line){
    if(!condition){
        std::cerr << "Assert failed:\t" << error_message << "\n"
            << "Expected:\t" << expected_expression << "\n"
            << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}