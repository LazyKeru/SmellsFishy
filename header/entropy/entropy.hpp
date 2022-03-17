/************************/
/**     Libraries      **/
/************************/
#include <String>
#include <Map>
#include <Cmath>
/************************/
/**     Functions      **/
/************************/
namespace Entropy
{
    /**
     * @brief Function to check if a string entropy fits between two value
     * 
     * @param _string The string we want to calculate the entropy of
     * @param entropy_min The minimum entropy the string must have
     * @param entropy_max The maximum entropy the string must have
     * @return true 
     * @return false 
     */
    bool stringFitEntropy(
        std::string _string,
        double entropy_min,
        double entropy_max
    );
    /**
     * @brief Function to calculate the entropy of a string 
     * 
     * @param _string The string we want to calculate the entropy of
     * @return double 
     */
    double entropy(
        std::string _string 
    );
    /**
     * @brief Calcule the log of base "base" for x
     * 
     * @param x x in "log base (x)"
     * @param base base in "log base (x)" default 2
     * @return double 
     */
    double local_log(
        double x, 
        double base = 2
    );
} // namespace name
