#include "../../header/rule/rule.hpp"

std::shared_ptr<rule::rule> rule::initRule(std::string name, std::string description, std::string regex, double maxEntropy, double minEntropy){
    std::shared_ptr<rule> res;
    res.get()->name = name;
    res.get()->description = description;
    res.get()->regex = regex;
    res.get()->maxEntropy = maxEntropy;
    res.get()->minEntropy = minEntropy;
    return res;
}

void rule::printRule(std::shared_ptr<rule> rule_ptr){
    std::cout 
        << "[" << rule_ptr.get()->name << "] : " << rule_ptr.get()->description << "\n"
        << " - regex : " << rule_ptr.get()->regex << "\n"
        << " - maxEntropy : " << rule_ptr.get()->maxEntropy << "\n"
        << " - minEntropy : " << rule_ptr.get()->minEntropy << "\n";
}