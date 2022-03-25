#pragma once
/************************/
/**      Includes      **/
/************************/
#include <string>
struct Argument
{
    //// Methods ////
    /**
     * @brief Construct a new Argument object
     */
    Argument(bool needInput, std::string flag[2]);
    //// Variables ////
    static constexpr int FLAG_SIZE = 2;
    bool defined;
    bool needInput;
    std::string value;
    std::string flag[FLAG_SIZE];
};