#pragma once
/************************/
/**      Includes      **/
/************************/
#include "../struct/secretsPerFile.hpp"
#include "../files/readDir.hpp"
#include "../util/log.hpp"
#include "../util/argument.hpp"
#include "../util/line_parser.hpp"
#include "../files/json.hpp"
#include <fstream>
#include <map>
#include <list>
#include <thread>
#include <functional>
#include <fstream>

class Core
{
public:
    /**
     * @brief help message
     * 
     */
    static void help();
    /**
     * @brief How to use message
     * 
     */
    static void usage();
    /**
     * @brief Warning message
     * 
     */
    static void warning();
    /**
     * @brief Analyze the entered directory with the entered rules. Will check if the entropy is active or not
     * 
     * @param dir 
     * @param rules 
     * @param entropy 
     * @return true 
     * @return false 
     */
    static bool analyze(const Argument &dir, const Argument &rules, const Argument &entropy);
    /**
     * @brief extracts the arguments, and acts according to the entered arguments
     * 
     * @param argc the number of arg
     * @param argv the argument list
     */
    static void arg(int argc, char *argv[]);
    /**
     * @brief Construct a new Core object
     * 
     */
    Core(const Core &) = delete;
    /**
     * @brief Function to output the log of all the secrets
     * 
     * @param log log Argument with as a value a path
     */
    static void log_output(const Argument &log){
        return instance._impl_logOutput(log.value);
    };
    /**
     * @brief Get the All Secrets objects
     * @return const std::vector<SecretsPerFile>&
     */
    static const std::vector<SecretsPerFile> &getAllSecrets()
    {
        return instance._impl_getAllSecrets();
    }
    /**
     * @brief Get the All Secrets objects
     * @return const std::vector<SecretsPerFile>&
     */
    static const std::vector<SecretsPerFile> &checkEntropySecrets()
    {
        return instance._impl_checkEntropySecrets();
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
    std::vector<SecretsPerFile> &_impl_getAllSecrets();
    std::vector<SecretsPerFile> &_impl_checkEntropySecrets();
    void _impl_logOutput(const std::string &path);
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

