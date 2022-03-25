#pragma once
/************************/
/**      Includes      **/
/************************/
#include <string>
#include <vector>
#include "./argument.hpp"
/************************/
/**     Namespace      **/
/************************/
namespace Line_parser
{
    /**
     * @brief Checks if the argument is in the argv, and if their is an input, it will save it
     * 
     * @param argument the argument we want to find
     * @param argv 
     * @param argc 
     */
    void find_argument(Argument * argument, char *argv[], int argc);
    /**
     * @brief Check all the arguments
     * 
     * @param arguments pointer to the vector of all the Arguments
     * @param argv 
     * @param argc 
     */
    void check_arguments(std::vector<Argument> * argument, char *argv[], int argc);
} // namespace Line_parser
