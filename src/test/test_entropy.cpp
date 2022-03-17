#include "../../header/test/test.hpp"
#include "../../header/entropy/entropy.hpp"
#include <iostream>

/**
 * @brief To be written
 * 
 * @return true 
 * @return false 
 */

/**************************/
/* CONST                  */
/**************************/
constexpr char* PHRASE = "This is an outrageous test";
constexpr double EXPECTED_VALUE = 3.51;

bool test::entropy()
{
    std::string test_string = PHRASE;
    double test_entropy = Entropy::entropy(test_string);
    std::cout << "The entropy of '" << PHRASE << "' is " << test_entropy << "\n";
    /* Testing if we obtained the correct entropy */
    if(std::round(EXPECTED_VALUE * 100) == std::round(test_entropy * 100)){
        std::cout << "Error: it wasn't the expected value\n";
        return false;
    }
    std::cout << "It is the expected value\n";
    std::cout << "Running stringFitEntropy, which should return true\n";
    if(Entropy::stringFitEntropy(test_string, EXPECTED_VALUE - 0.01, EXPECTED_VALUE + 0.01) != true){
        std::cout << "Error: It was suppose to fit\n";
        return false;
    }
    std::cout << "Did return true\n";
    /* Testing the stringFitEntropy function. Should work without a problem */
    return true;
}