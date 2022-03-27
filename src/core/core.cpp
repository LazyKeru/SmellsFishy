#include "../../header/core/core.hpp"
#include "../../header/files/readDir.hpp"
#include "../../header/regex/regex.hpp"
#include "../../header/files/fileToString.hpp"
#include <functional>
#include <future>

// Déclaration pour le linker
Core Core::instance;

static SecretsPerFile threadFunction(std::string path, std::map<std::string, std::shared_ptr<Rule>> *r)
{
	SecretsPerFile secrets(path);
	const auto fileString = Files::fileToString(path);
	const auto &rules = *r;
	for (const auto &[rulename, rule] : rules)
	{
		auto allFoundStrings = Regex::findAll(rule->regex, fileString);
		secrets.reserve(allFoundStrings.size());
		for (const auto &secretString : allFoundStrings)
			secrets.addSecret(Secret(rule, secretString, -1));
	}

	return secrets;
}

const std::vector<SecretsPerFile> &Core::_impl_getAllSecrets()
{
	std::vector<std::string> allPaths;
	for (const auto &path : paths)
	{
		if (Files::isDir(path))
		{
			auto fpaths = Files::readDirRecursive(path);
			allPaths.insert(allPaths.end(), fpaths.begin(), fpaths.end());
		}
		else
			allPaths.push_back(path);
	}
	secrets.reserve(allPaths.size());
	std::vector<std::future<SecretsPerFile>> results(std::thread::hardware_concurrency());
	for (int i = 0; i < allPaths.size(); i++)
	{
		int j = 0;

		for (; i < allPaths.size() && j < results.size(); i++, j++)
			results[j] = std::async(std::launch::async, threadFunction, allPaths[i], &rules);

		for (int k = 0; k < j; k++)
			results[k].wait();

		for (int k = 0; k < j; k++)
			secrets.push_back(results[k].get());
	}

	return secrets;
}

void Core::_impl_addRule(std::shared_ptr<Rule> ruleToAdd)
{
	rules.emplace(ruleToAdd->name, ruleToAdd);
}

void Core::_impl_removeRule(const std::string &ruleName)
{
	rules.erase(ruleName);
}

void Core::_impl_f()
{
	for (const auto &r : rules)
		r.second->print();
	for (const auto &p : paths)
		std::cout << p << std::endl;
}

void Core::_impl_addPath(const std::string &newPath)
{
	paths.push_back(newPath);
}
void Core::_impl_removePath(const std::string &pathToRemove)
{
	paths.remove(pathToRemove);
}

Core::Core()
{
}

// Core::CoreThread::CoreThread(const std::map<std::string, std::shared_ptr<Rule>> &r) : rules(r), done(true), thread(nullptr)
// {
// 	threadFunction = [this](const std::string &path)
// 	{
// 		std::cout << std::this_thread::get_id() << "begin";
// 		const auto fileString = Files::fileToString(path);
// 		for (const auto &[rulename, rule] : rules)
// 		{
// 			auto allFoundStrings = Regex::findAll(rule->regex, fileString);
// 			std::cout << "found" << allFoundStrings.size() << '\n';
// 			secrets.reserve(allFoundStrings.size());
// 			for (const auto &secretString : allFoundStrings)
// 				secrets.addSecret(Secret(rule, secretString, -1));
// 		}
// 		std::cout << std::this_thread::get_id() << "end";
// 	};
// }

// Core::CoreThread::~CoreThread()
// {
// 	delete thread;
// }

// void Core::CoreThread::find(const std::string &path)
// {
// 	done = false;
// 	delete thread;
// 	thread = new std::thread(&threamdFunction, path);
// 	done = true;
// }
