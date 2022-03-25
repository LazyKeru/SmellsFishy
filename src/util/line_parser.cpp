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
    current = argv[ptr];
    argument->value = current;
}
/**
 * @brief Check for all the arguments
 * 
 * @param arguments pointer to the vector of all the Arguments
 * @param argv 
 * @param argc 
 */
void Line_parser::check_arguments(std::vector<Argument> * arguments, char *argv[], int argc){
    for (int i = 0; i < arguments->size(); i++)
    {
        find_argument(&arguments->at(i), argv, argc);
    }
}