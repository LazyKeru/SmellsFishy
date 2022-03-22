/************************/
/**      Includes      **/
/************************/
#include <string>
#include <iostream>
#include <memory>
/************************/
/**       Struct       **/
/************************/
/**
 * @brief The structure for a rule (used to detect secrets)
 *
 */
struct Rule
{
    //// Static Methods ////
    /**
     * @brief Construct a new Rule object
     */
    static std::shared_ptr<Rule> getRuleSharedPtr(const Rule &r);
    

    //// Methods ////
    /**
     * @brief Construct a new Rule object
     *
     * @param regex regex of the rule
     * @param maxEntropy max entropy it shouldn't go over
     * @param minEntropy min entropy it shouldn't go under default 0
     * @return rule
     */
    Rule(const std::string &name, const std::string &description, const std::string &regex, double maxEntropy, double minEntropy = 0);

    /**
     * @brief prints the rule
     */
    void print() const;


    //// Variables ////
    std::string name;
    std::string description;
    std::string regex;
    double maxEntropy;
    double minEntropy;
};
