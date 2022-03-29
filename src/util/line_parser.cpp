/*********************************************/
/**            Library             **/
/*********************************************/
#include "../../header/util/line_parser.hpp"
/*********************************************/
/**            START TO ANALYSE             **/
/*********************************************/
/**
 * @brief Checks if the argument is in the argv, and if their is an input, it will save it
 * 
 * @param argument the argument we want to find
 * @param argv 
 * @param argc 
 */
void Line_parser::find_argument(Argument * argument, char *argv[], int argc){
    int ptr = -1;
    std::string current;
    for(int i = 0; i < argument->FLAG_SIZE; i++)
    {   
        for (int j = 1; j < argc; j++)
        {
            current = argv[j];
            if ((current == argument->flag[i]) && (ptr == -1)){
                ptr = j;
            }
        }
    }
    if(ptr==-1){
        //doesn't exist
        return;
    }
    if(!argument->needInput){
        argument->defined = true;
        return;
    }
    if(++ptr==argc){
        //missing input
        return;
    }
    // if(current[0]=="-"){
    //     //missing input
    //     return;
    // }
    current = argv[ptr];
    argument->value = current;
    argument->defined = true;
}
/**
 * @brief Check for all the arguments
 * 
 * @param arguments pointer to the vector of all the Arguments
 * @param argv 
 * @param argc 
 */
void Line_parser::check_arguments(std::vector<Argument> * arguments, char *argv[], int argc){
    for (std::string::size_type i = 0; i < arguments->size(); i++)
    {
        find_argument(&arguments->at(i), argv, argc);
    }
}
/**
 * @brief 
 * 
 * @param arguments 
 * @param argc 
 * @return true 
 * @return false 
 */
bool Line_parser::ammountArguments(std::vector<Argument> * arguments, int argc){
    int count = 0;
    for (std::string::size_type i = 0; i < arguments->size(); i++)
    {
        if (arguments->at(i).defined)
        {
            // An argument is needed
            ++count;
            if (arguments->at(i).needInput)
            {
                // An argument is needed
                ++count;
            }
        }
    }
    if(count == argc-1){
        return true;
    }
    return false;
}