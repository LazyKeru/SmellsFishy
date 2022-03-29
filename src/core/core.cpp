#include "../../header/core/core.hpp"
#include "../../header/files/readDir.hpp"
#include "../../header/regex/regex.hpp"
#include "../../header/files/fileToString.hpp"
#include <functional>
#include <future>

// Déclaration pour le linker
Core Core::instance;

static SecretsPerFile threadFunction(std::string path, std::map<std::string, std::shared_ptr<Rule>>* r)
{
	SecretsPerFile secrets(path);

	const auto fileString = Files::fileToString(path);
	const auto& rules = *r;
	for (const auto& [rulename, rule] : rules)
	{
		try {
			auto allFoundStrings = Regex::findAll(rule->regex, fileString);
		}
		catch (std::regex_error err) {
			std::cout << "ERROR WITH THIS RULE" << std::endl;
			rule->print();

			std::cout << err.what() << std::endl << std::endl;
		}
		secrets.reserve(allFoundStrings.size());
		for (const auto &secretString : allFoundStrings)
			secrets.addSecret(Secret(rule, secretString, -1));
	}

	return secrets;
}

const std::vector<SecretsPerFile>& Core::_impl_getAllSecrets()
{
	std::vector<std::string> allPaths;
	for (const auto& path : paths)
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

#if SINGLE_CORE
	std::vector<SecretsPerFile> results;
	results.resize(1);
#else
	std::vector<std::future<SecretsPerFile>> results;
	results.resize(std::thread::hardware_concurrency());
#endif

	for (int i = 0; i < allPaths.size(); i++)
	{
		int j = 0;
#if SINGLE_CORE
		for (; i < allPaths.size(); i++) {
			results[0] = threadFunction(allPaths[i], &rules);
			secrets.push_back(results[0]);
		}

#else
		for (; i < allPaths.size() && j < results.size(); i++, j++)
			results[j] = std::async(std::launch::async, threadFunction, allPaths[i], &rules);
		for (int k = 0; k < j; k++)
			results[k].wait();

		for (int k = 0; k < j; k++) {
			std::cout << k << ": ";
			auto res = results[k].get();
			res.print();
			std::cout << std::endl;

		}
		for (int k = 0; k < j; k++)
			secrets.push_back(results[k].get());
#endif
	}

	return secrets;
}

void Core::_impl_addRule(std::shared_ptr<Rule> ruleToAdd)
{
	rules.emplace(ruleToAdd->name, ruleToAdd);
}

void Core::_impl_removeRule(const std::string& ruleName)
{
	rules.erase(ruleName);
}

void Core::_impl_addPath(const std::string& newPath)
{
	paths.push_back(newPath);
}
void Core::_impl_removePath(const std::string& pathToRemove)
{
	paths.remove(pathToRemove);
}

Core::Core()
{
}

void Core::_impl_loadJson(const std::string& jsonPath)
{
	json = std::make_unique<JSON>(jsonPath);
}

void Core::_impl_addRuleFromJSON(const std::string& ruleDescription)
{
	if (json) // si le pointeur a été initialisé
		addRule(std::make_shared<Rule>(json->getRuleFromDescription(ruleDescription)));
}

void Core::_impl_loadAllRulesFromJSON()
{
	if (!json)
		return;

	auto v = json->getAllRulesFromJSON();
	int i = 0;
	for (const auto& r : v)
	{
		std::cout << i++ << std::endl;
		addRule(std::make_shared<Rule>(r));
	}
}