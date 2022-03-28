#pragma once
/************************/
/**      Includes      **/
/************************/
#include "../struct/secretsPerFile.hpp"
#include "../files/readDir.hpp"
#include "../files/json.hpp"
#include "../util/log.hpp"
#include <map>
#include <list>
#include <thread>
#include <functional>

class Core
{
public:
    static void help();
    static void usage();
    static void warning();
    static void analyze(std::string dir, std::string rules);

    Core(const Core &) = delete;

    /**
     * @brief adds a rule tu the rule set
     * 
     * @param ruleDescription the description of the rule in the json
     */
    static void addRuleFromJSON(const std::string& ruleDescription)
    {
        instance._impl_addRuleFromJSON(ruleDescription);
    }

    /**
     * @brief loads json into core to read rules from it
     */
    static void loadJson(const std::string& jsonPath)
    {
        instance._impl_loadJson(jsonPath);
    }
    /**
     * @brief Get the All Secrets objects
     * @return const std::vector<SecretsPerFile>&
     */
    static const std::vector<SecretsPerFile> &getAllSecrets()
    {
        return instance._impl_getAllSecrets();
    }

    /**
     * @brief adds a rule to the existing ones
     */
    static void addRule(std::shared_ptr<Rule> ruleToAdd)
    {
        instance._impl_addRule(ruleToAdd);
    }

    /**
     * @brief removes the rule that has the name you give
     */
    static void removeRule(const std::string &ruleName)
    {
        instance._impl_removeRule(ruleName);
    }

    /**
     * @brief adds a path to the pathList. Can be file or directory
     */
    static void addPath(const std::string &newPath)
    {
        instance._impl_addPath(newPath);
    }

    /**
     * @brief remove the path you give from the pathList
     *
     */
    static void removePath(const std::string &pathToRemove)
    {
        instance._impl_removePath(pathToRemove);
    }

private: // Singleton related
    const std::vector<SecretsPerFile> &_impl_getAllSecrets();
    void _impl_addRule(std::shared_ptr<Rule> ruleToAdd);
    void _impl_removeRule(const std::string &ruleName);
    void _impl_addPath(const std::string &newPath);
    void _impl_removePath(const std::string &newPath);
    void _impl_loadJson(const std::string& jsonPath);
    void _impl_addRuleFromJSON(const std::string& ruleDescription);

    Core();
    static Core instance;

private: // Attributes
    std::unique_ptr<JSON> json;
    std::map<std::string, std::shared_ptr<Rule>> rules;
    std::list<std::string> paths;
    std::vector<SecretsPerFile> secrets;
};

