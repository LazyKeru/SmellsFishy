#pragma once

/************************/
/**      Includes      **/
/************************/
#include <string>
#include <map>
#include <cmath>
#include <memory>
#include <iostream>
#include "./rule.hpp"

/************************/
/**       Struct       **/
/************************/
/**
 * @brief Struct of a detected secret
 *
 */
struct Secret
{
    //// Methods ////
    /**
     * @brief Construct a new Secret object
     */
    Secret();

    /**
     * @brief Construct a new Secret object
     *
     * @param rule_ptr shared_ptr to the broken rule
     * @param matchedRegex The string which matched the regex rule
     * @param lineNumber The line number in the file
     * @param entropy The entropy of the matchedRegex
     * @return secret
     */
    Secret(std::shared_ptr<Rule> rule_ptr, std::string matchedRegex, int lineNumbre, double entropy = -1);

    /**
     * @brief Prints the secret
     */
    void print() const;

    //// Variables ////
    std::shared_ptr<Rule> rulePtr;
    std::string matchedRegex;
    int lineNumber;
    double entropy;
};