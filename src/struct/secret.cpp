#include "../../header/struct/secret.hpp"
#include "../../header/util/log.hpp"

INIT_LOG

Secret::Secret() : lineNumber(-1), entropy(-1.0)
{
}

Secret::Secret(std::shared_ptr<Rule> rule_ptr, std::string matched_regex, int line_number, double entropy) :
    rulePtr(rule_ptr), matchedRegex(matched_regex), lineNumber(line_number), entropy(entropy)
{
}

void Secret::print() const
{
    Log::msg 
        << "[Detected Secret] " << matchedRegex << "\n"
        << " - Broken rule : " << rulePtr->name << "\n"
        << " - lineNumber : " << lineNumber << "\n"
        << " - entropy : " << entropy << "\n";
}