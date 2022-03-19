#include "../../header/rule/rule.hpp"

rule::rule rule::initRule(std::string name, std::string description, std::string regex, double maxEntropy, double minEntropy){
    rule res;
    res.name = name;
    res.description = description;
    res.regex = regex;
    res.maxEntropy = maxEntropy;
    res.minEntropy = minEntropy;
    return res;
}

void rule::printRule(rule rule){
    std::cout 
        << "[" << rule.name << "] : " << rule.description << "\n"
        << " - regex : " << rule.regex << "\n"
        << " - maxEntropy : " << rule.maxEntropy << "\n"
        << " - minEntropy : " << rule.minEntropy << "\n";
}