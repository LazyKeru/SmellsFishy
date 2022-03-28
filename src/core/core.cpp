#include "../../header/core/core.hpp"
#include "../../header/files/readDir.hpp"
#include "../../header/regex/regex.hpp"
#include "../../header/entropy/entropy.hpp"
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

const std::vector<SecretsPerFile> &Core::_impl_checkEntropySecrets()
{
	bool _entropy;
	double _minEntropy;
	for (size_t i = 0; i < secrets.size(); i++)
	{
		for (size_t j = 0; j < secrets[i].secretList.size(); j++)
		{
			if(secrets[i].secretList[j].rulePtr->maxEntropy){
				if(!secrets[i].secretList[j].rulePtr->minEntropy){
					_minEntropy = 0;
				}else{
					_minEntropy = secrets[i].secretList[j].rulePtr->minEntropy;
				}
				if(!Entropy::stringFitEntropy(
					secrets[i].secretList[j].matchedRegex, 
					secrets[i].secretList[j].rulePtr->maxEntropy, 
					_minEntropy
				)){
					secrets[i].secretList.erase(
						secrets[i].secretList.begin()
						+ i
					);
					--i;
				}
			}
		}
		
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
