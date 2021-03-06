#include "../../header/core/core.hpp"

INIT_LOG

bool Core::analyze(const Argument &dir, const Argument &rules, const Argument &entropy){
    /** ASSIGNING THE ARGS **/
    std::string _rules = rules.value;
    std::string _dir = dir.value;
    /** EXECUTING THE *future* FUNCTION **/
    Core::addPath(_dir);
    Core::loadJson(rules.value);
    Core::loadAllRulesFromJSON();
    auto secrets(Core::getAllSecrets());
    if(entropy.defined)
    {
        secrets = Core::checkEntropySecrets();
    }
    if (secrets.size() != 0)
    {
        std::cout << "No secrets found!\n";
        return true;
    }
    for (const auto &scts : secrets)
    {

        std::cout << "\n\n\t\tTESTING FILE " << scts.file_path << "\n\n";
        for (const auto &sct : scts)
            std::cout << sct.rulePtr->description << "\t" << sct.matchedRegex << "\t" << sct.lineNumber << '\n' ;
    }
    return false;
}

void Core::_impl_logOutput(const std::string &path){
    std::string outFile(path);
    std::ofstream out(outFile);
    for (const auto &scts : secrets)
    {
        if(scts.secretList.size() != 0){
            out << "\n\n\t\tANALYZED FILE " << scts.file_path << "\n\n";
            for (const auto &sct : scts)
                out << sct.rulePtr->description << "\t" << sct.matchedRegex << '\n';
        }
    }
    out.close();

}