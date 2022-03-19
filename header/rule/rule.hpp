/************************/
/**      Includes      **/
/************************/
#include <string>
#include <iostream>
/************************/
/**     Functions      **/
/************************/
namespace rule
{
    /**
     * @brief 
     * 
     */
    typedef struct rule
    {   
        std::string name;
        std::string description;
        std::string regex;
        double maxEntropy;
        double minEntropy;
    }rule;
    /**
     * @brief init a rule
     * 
     * @param regex 
     * @param maxEntropy 
     * @param minEntropy 
     * @return rule 
     */
    rule initRule(std::string name, std::string description, std::string regex, double maxEntropy, double minEntropy);
    /**
     * @brief Simply print the rule.
     * 
     */
    void printRule(rule);
} // namespace rule
