#include "../../header/entropy/entropy.hpp"

bool Entropy::stringFitEntropy(const std::string& _string, double entropy_min, double entropy_max){
    // Checking if the parameters are valid
    if(entropy_min>=entropy_max)
        return false;
    // Calculating the entropy of the string
    double _stringEntropy = Entropy::entropy(_string);
    // Checking if _stringEntropy fits between entropy_min and entropy_max
    if((_stringEntropy >= entropy_min) && (_stringEntropy <= entropy_max))
        return true;
    // Default response
    return false;
}

double Entropy::entropy(const std::string& _string){
    std::map<char, int> frequencies;
    // looping threw the frequencies
    for (size_t i = 0; i < _string.size(); i++)
        frequencies[_string[i]] ++; // Incrementing the total amount of the current caracter found
    // Amount of information
    double total_information = _string.size();
    double res = 0;
    // Calculating the Entropy according to the information theory
    for (auto const& [symbol, amount] : frequencies)
    {
        double Px = amount / total_information;
        res += Px * Entropy::local_log(Px);
    }
    res *= -1;
    return res;
}

double Entropy::local_log(double x, double base){
    // log b (x) = ln(x) / ln(base)
    return (double) log(x) / log(base);
}
