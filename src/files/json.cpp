#include "../../header/files/json.hpp"
#include "../../header/files/fileToString.hpp"
#include "../../header/util/util.hpp"

JSON::JSON(const std::string &jsonPath) : json(nlohmann::json::parse(Files::fileToString(jsonPath)))
{
}

std::vector<Rule> JSON::getAllRulesFromJSON()
{
    std::vector<Rule> vec;
    vec.reserve(json["rules"].size());

    for (const auto &r : json["rules"]){
        double maxEntropy = -1;
        if(r.contains("maxEntropy")){
            maxEntropy = r["maxEntropy"];
        }
        double minEntropy = -1;
        if(r.contains("minEntropy")){
            minEntropy = r["minEntropy"];
        }
        vec.push_back(Rule(
            std::string(r["id"]), std::string(r["description"]),
            std::string(r["regex"]), maxEntropy, minEntropy
        ));
    }

    return vec;
}

Rule JSON::getRuleFromDescription(const std::string &description)
{
    auto rule = json["rules"][getIndexWhereRuleEquals("description", description)];
    std::string name(rule["id"]);
    std::string desc(rule["description"]);
    std::string reg(rule["regex"]);
    double maxEntropy;
    if(rule["maxEntropy"]){
        maxEntropy = rule["maxEntropy"];
    }else{
        maxEntropy = not_a_number;
    }
    double minEntropy;
    if(rule["minEntropy"]){
        minEntropy = rule["minEntropy"];
    }else{
        minEntropy = not_a_number;
    }
    Rule r(name, desc, reg, maxEntropy, minEntropy);
    // Rule r(std::string(rule["id"]), std::string(rule["description"]), std::string(rule["regex"]),
    //        not_a_number, not_a_number);
    return r;
}
// Rule JSON::getRuleFromName(const std::string &name)
// {
//     return Rule();
// }
// Rule JSON::getRuleFromRegex(const std::string &regex)
// {
//     return Rule();
// }

int JSON::getIndexWhereRuleEquals(const std::string &field, const std::string &condition)
{
    auto rules = json["rules"];

    for (std::string::size_type i = 0; i < rules.size(); i++)
    {
        std::string s = rules[i][field];
        if (s == condition)
            return i;
    }

    return -1;
}
