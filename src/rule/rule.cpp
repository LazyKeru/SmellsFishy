#include "../../header/rule/rule.hpp"

std::shared_ptr<rule::rule> rule::initRule(std::string name, std::string description, std::string regex, double maxEntropy, double minEntropy){
    std::cout << "[Structure - Rule] log: start initRule\n";
    auto res = std::shared_ptr<rule>(new rule);
    res->name = name;
    res->description = description;;
    res->regex = regex;
    res->maxEntropy = maxEntropy;
    res->minEntropy = minEntropy;
    return res;
}

void rule::printRule(std::shared_ptr<rule> rule_ptr){
    std::cout 
        << "[" << rule_ptr.get()->name << "] : " << rule_ptr.get()->description << "\n"
        << " - regex : " << rule_ptr.get()->regex << "\n"
        << " - maxEntropy : " << rule_ptr.get()->maxEntropy << "\n"
        << " - minEntropy : " << rule_ptr.get()->minEntropy << "\n";
}