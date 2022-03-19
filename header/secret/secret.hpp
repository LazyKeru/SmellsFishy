/************************/
/**      Includes      **/
/************************/
#include <string>
#include <map>
#include <cmath>
#include <memory>
#include <iostream>
#include "../rule/rule.hpp"
/************************/
/**     Functions      **/
/************************/
namespace secret
{
    /**
     * @brief Struct of a detected secret, for the secrets detected in a specific file
     * 
     */
    typedef struct secret
    {
        std::shared_ptr<rule::rule> rule_ptr;
        std::string matchedRegex;
        int lineNumbre;
        double entropy;
    }secret;
    /**
     * @brief Create a secret
     * 
     * @param matchedRegex The string which matched the regex rule
     * @param lineNumbre The line number in the file
     * @param entropy The entropy
     * @return secret 
     */
    secret initSecret(std::shared_ptr<rule::rule> rule_ptr, std::string matchedRegex, int lineNumbre, double entropy = -1);
    /**
     * @brief Set the Entropy
     * 
     * @param secret the secret which we want to update the entropy
     * @param newEntropy the new entropy value
     */
    void setSecretEntropy(secret *secret, double newEntropy);
    /**
     * @brief Print info in the console about the secret
     * 
     * @param secret 
     */
    void printSecret(secret secret);
} // namespace secret