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
    static const std::vector<SecretsPerFile> &getAllSecrets()
    {
        return instance._impl_getAllSecrets();
    }
    static void addRule(std::shared_ptr<Rule> ruleToAdd)
    {
        instance._impl_addRule(ruleToAdd);
    }
    static void removeRule(const std::string &ruleName)
    {
        instance._impl_removeRule(ruleName);
    }
    static void f()
    {
        instance._impl_f();
    }
    static void addPath(const std::string &newPath)
    {
        instance._impl_addPath(newPath);
    }
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

    void _impl_f();
    Core();
    static Core instance;

public:
    // class CoreThread
    // {
    // public:
    //     CoreThread(const std::map<std::string, std::shared_ptr<Rule>>& r);
    //     ~CoreThread();
    //     void find(const std::string &path);
    //     void join() { thread->join(); }
    //     const SecretsPerFile &getSecrets() const { return secrets; }
    //     bool isDone() { return done; }

    //     std::function<void(const std::string&)> threadFunction;
    // private:
    //     bool done;
    //     SecretsPerFile secrets;
    //     std::thread* thread;
    //     const std::map<std::string, std::shared_ptr<Rule>> &rules;
    // };

private: // Attributs
    std::map<std::string, std::shared_ptr<Rule>> rules;
    std::list<std::string> paths;
    std::vector<SecretsPerFile> secrets;
    // std::vector<CoreThread> threads;
};
