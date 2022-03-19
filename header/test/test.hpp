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
    /**
     * @brief Test function for the regex functions
     * 
     * @return true 
     * @return false 
     */
	bool regex();
    /**
     * @brief Test function for the fileToString functions
     * 
     * @return true 
     * @return false 
     */
    bool fileToString();
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