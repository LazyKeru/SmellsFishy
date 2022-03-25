#include "../../header/struct/rule.hpp"
#include "../../header/util/log.hpp"

INIT_LOG

std::shared_ptr<Rule> Rule::getRuleSharedPtr(const Rule &r)
{
    return std::make_shared<Rule>(r);
}

Rule::Rule(const std::string& name, const std::string& description, const std::string& regex, double maxEntropy, double minEntropy) :
    name(name), description(description), regex(regex), maxEntropy(maxEntropy), minEntropy(minEntropy)
{
}

void Rule::print() const
{
    Log::msg 
        << "[" << name << "] : " << description << "\n"
        << " - regex : " << regex << "\n"
        << " - maxEntropy : " << maxEntropy << "\n"
        << " - minEntropy : " << minEntropy << "\n";
}