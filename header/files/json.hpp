#include "../external/json_lib.hpp"
#include "../struct/rule.hpp"

class JSON
{
public:
    JSON(const std::string &jsonPath);

    Rule getRuleFromDescription(const std::string &description);
    Rule getRuleFromName(const std::string &name);
    Rule getRuleFromRegex(const std::string &regex);

private:
    int getIndexWhereRuleEquals(const std::string& field, const std::string& condition);
    nlohmann::json json;
};