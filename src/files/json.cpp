#include "../../header/files/json.hpp"
#include "../../header/files/fileToString.hpp"
#include "../../header/util/util.hpp"

JSON::JSON(const std::string &jsonPath) : json(nlohmann::json::parse(Files::fileToString(jsonPath)))
{
}

Rule JSON::getRuleFromDescription(const std::string &description)
{
    auto rule = json["rules"][getIndexWhereRuleEquals("description", description)];
    std::string name(rule["id"]);
    std::string desc(rule["description"]);
    std::string reg(rule["regex"]);
    Rule r(name, desc, reg, not_a_number, not_a_number);
    // Rule r(std::string(rule["id"]), std::string(rule["description"]), std::string(rule["regex"]),
    //        not_a_number, not_a_number);
    return r;
}
Rule JSON::getRuleFromName(const std::string &name)
{
    return Rule();
}
Rule JSON::getRuleFromRegex(const std::string &regex)
{
    return Rule();
}

int JSON::getIndexWhereRuleEquals(const std::string &field, const std::string &condition)
{
    auto rules = json["rules"];

    for (int i = 0; i < rules.size(); i++)
    {
        std::string s = rules[i][field];
        if (s == condition)
            return i;
    }

    return -1;
}
