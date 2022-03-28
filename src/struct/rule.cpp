#include "../../header/struct/rule.hpp"
#include "../../header/util/util.hpp"
#include "../../header/util/log.hpp"

INIT_LOG

std::shared_ptr<Rule> Rule::getRuleSharedPtr(const Rule &r)
{
    return std::make_shared<Rule>(r);
}

Rule::Rule(const std::string& _name, const std::string& _description, const std::string& _regex, double maxEntropy, double minEntropy) :
    name(_name), description(_description), regex(_regex), maxEntropy(maxEntropy), minEntropy(minEntropy)
{
}

Rule::Rule(const std::string& _name, const std::string& _description, const std::string& _regex) :
    name(_name), description(_description), regex(_regex), maxEntropy(-1), minEntropy(-1)
{
}


void Rule::print() const
{
    Log::msg 
        << "\n - name : " << name << '\n' 
        << " - description : " << description << '\n'
        << " - regex : " << regex << "\n"
        << " - maxEntropy : " << maxEntropy << "\n"
        << " - minEntropy : " << minEntropy << "\n";
}