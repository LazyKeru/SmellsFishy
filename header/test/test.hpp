#pragma once
/************************/
/**      Includes      **/
/************************/
#include <string>
#include <iostream>
#include "../util/log.hpp"
/************************/
/**     Functions      **/
/************************/
namespace test
{
    bool regex();
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
    /*
     * @brief Test function for the files related functions
     *
     * @return true
     * @return false
     */
    bool files();

    bool core();

    int createTestFiles(const std::string &root, const std::string &stringInFiles);
        void deleteTestFiles(const std::string &path);

}