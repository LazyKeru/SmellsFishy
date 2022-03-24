#include "../../header/struct/rule.hpp"
#include "../../header/util/util.hpp"

std::shared_ptr<Rule> Rule::getRuleSharedPtr(const Rule &r)
{
    return std::make_shared<Rule>(r);
}

Rule::Rule(const std::string& _name, const std::string& _description, const std::string& _regex, double maxEntropy, double minEntropy) :
    name(_name), description(_description), regex(_regex), maxEntropy(maxEntropy), minEntropy(minEntropy)
{
}

void Rule::print() const
{
    std::cout 
        << "[" << name << "] : " << description << "\n"
        << " - regex : " << regex << "\n"
        << " - maxEntropy : " << maxEntropy << "\n"
        << " - minEntropy : " << minEntropy << "\n";
}