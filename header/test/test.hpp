#pragma once
/************************/
/**      Includes      **/
/************************/
#include <string>
#include <iostream>
/************************/
/**     Functions      **/
/************************/

namespace test
{
    enum class logType
    {
        message,
        warning,
        error
    };
    void log(const std::string &messge, const std::string &filePath = "", logType log_type = logType::message);
    /**
     * @brief Test function for the regex functions
     * 
     * @return true 
     * @return false 
     */
    bool regex();
    /**
     * @brief Test function for the fileToString function
     *
     * @return true
     * @return false
     */
    bool files();
    /**
     * @brief Test function for the entropy functions
     * 
     * @return true 
     * @return false 
     */
    bool entropy();
    /**
     * @brief Test function for the secret and rule functions and structures
     * 
     * @return true 
     * @return false 
     */
    bool structure();
}