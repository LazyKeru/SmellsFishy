#include "../../header/test/test.hpp"
#include "../../header/core/core.hpp"
#include "../../header/files/json.hpp"
#include "../../header/struct/secret.hpp"
#include <fstream>


INIT_LOG

bool test::core()
{
    std::string outFile("log.txt");
    std::ofstream out(outFile);
    Log::msg << "Loading JSON file...\n";
    Log::msg << "Preparing environment...\n";
    // auto root = "../../FilesTest";
    // test::deleteTestFiles(root);
    // auto s = "En informatique, une expression régulière ou expression rationnelle1 ou expression normalenote 1 ou motif est une chaîne de caractères qui décrit,"
    //          "selon une syntaxe précise, un ensemble de chaînes de caractères possibles. Les expressions régulières sont également appelées regex (un mot-valise formé depuis"
    //          "l'anglais regular expression). Les expressions rationnelles sont issues des théories mathématiques des langages formels des années 1940. Leur capacité à décrire"
    //          "avec concision des ensembles réguliers explique qu’elles se retrouvent dans plusieurs domaines scientifiques dans les années d’après-guerre et justifie leur"
    //          "adoption en informatique. Les expressions régulières sont aujourd’hui utilisées pour programmer des logiciels avec des fonctionnalités de lecture, de contrôle,"
    //          "de modification, et d'analyse de textes ainsi que dans la manipulation des langues formelles que sont les langages informatiques."
    //          "Ces expressions régulières ont la qualité de pouvoir être décrites par des formules ou motifs (en anglais patterns) bien plus simples que les autres moyens2.";
    // test::createTestFiles(root, s);
    Log::msg << "Adding playground path...\n";
    Core::addPath(R"(./playground/)");
    Log::msg << "Loading JSON into Core...\n";
    Core::loadJson(R"(./resources/default.json)");
    Log::msg << "Adding rule from the JSON...\n";
    Core::loadAllRulesFromJSON();
    Log::msg << "Finding all secrets\n";
    auto secrets(Core::getAllSecrets());
    secrets = Core::checkEntropySecrets();
    if (secrets.size() == 0)
    {
        Log::err << "No secrets found!\n";
        return false;
    }
    Log::msg << "Storing secrets in a file...\n";
    for (const auto &scts : secrets)
    {
        out << "\n\n\t\tTESTING FILE " << scts.file_path << "\n\n";
        for (const auto &sct : scts)
            out << sct.rulePtr->description << "\t" << sct.matchedRegex << '\n';
    }
    out.close();
    // if (std::filesystem::file_size(outFile) < 76000u || std::filesystem::file_size(outFile) > 80000u)
    // {
    //     Log::err << "Something's wrong with the file, the size seems out of bound!\n";
    //     std::filesystem::remove(outFile);
    //     return false;
    // }
    std::filesystem::remove(outFile);
    Log::msg << "Everything working normally\n";
    return true;
}
