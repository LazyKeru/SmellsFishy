#include <iostream>
#include "../header/regex/regex.hpp"
#include "../header/files/readDir.hpp"
#include <vector>
#include "../header/files/json.hpp"
#include "../header/struct/rule.hpp"
#include "../header/struct/secretsPerFile.hpp"
#include "../header/core/core.hpp"

int main(int argc, char const *argv[])
{
    JSON rgx_json("C:/Users/Eloi/Desktop/Projets/SmellsFishy/SmellsFishy/resources/rgx_list.json");
   
    std::vector<std::shared_ptr<Rule>> rules;

    Core::addRule(Rule::getRuleSharedPtr(rgx_json.getRuleFromDescription("PGP private key")));
    Core::addRule(Rule::getRuleSharedPtr(rgx_json.getRuleFromDescription("Shopify shared secret")));
    Core::addRule(Rule::getRuleSharedPtr(rgx_json.getRuleFromDescription("Slack token")));
    Core::addRule(Rule::getRuleSharedPtr(rgx_json.getRuleFromDescription("Discord client ID")));
    Core::addPath("C:/Users/Eloi/Desktop/Projets/SmellsFishy/SmellsFishy/src");
    Core::addPath("C:/Users/Eloi/Desktop/Projets/SmellsFishy/SmellsFishy/header");
    Core::getAllSecrets();

    auto files = Files::readDirRecursive("C:/Users/Eloi/Desktop/Projets/SmellsFishy");
    std::vector<SecretsPerFile> allSecrets(files.size());

    return 0;
}
