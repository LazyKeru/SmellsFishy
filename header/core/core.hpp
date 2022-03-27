#pragma once
#include "../struct/secretsPerFile.hpp"
#include <map>
#include <list>
#include <thread>
#include <functional>

class Core
{
public:
    Core(const Core &) = delete;
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

    Core();
    static Core instance;

private: // Attributes
    std::map<std::string, std::shared_ptr<Rule>> rules;
    std::list<std::string> paths;
    std::vector<SecretsPerFile> secrets;
};
