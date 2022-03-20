/************************/
/**      Includes      **/
/************************/
#include <string>
#include <iostream>
#include <memory>
/************************/
/**     Functions      **/
/************************/
namespace rule
{
    /**
     * @brief The structure for a rule (used to detect secrets)
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
     * @param regex regex of the rule
     * @param maxEntropy max entropy it shouldn't go over
     * @param minEntropy min entropy it shouldn't go under default 0
     * @return rule 
     */
    std::shared_ptr<rule> initRule(std::string name, std::string description, std::string regex, double maxEntropy, double minEntropy = 0);
    /**
     * @brief Simply print the rule.
     * 
     */
    void printRule(const std::shared_ptr<rule> & rule_ptr);
} // namespace rule
