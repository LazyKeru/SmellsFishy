#include "../../header/test/test.hpp"
#include "../../header/core/core.hpp"
#include "../../header/files/json.hpp"
#include "../../header/struct/secret.hpp"
#include <fstream>

INIT_LOG

bool test::core()
{
    std::ofstream out("log.txt");
    JSON json(R"(C:\Users\Eloi\Desktop\Projets\SmellsFishy\SmellsFishy\resources\rgx_list.json)");
    auto root = "../../FilesTest";
    test::deleteTestFiles(root);
    auto s = "En informatique, une expression régulière ou expression rationnelle1 ou expression normalenote 1 ou motif est une chaîne de caractères qui décrit,"
             "selon une syntaxe précise, un ensemble de chaînes de caractères possibles. Les expressions régulières sont également appelées regex (un mot-valise formé depuis"
             "l'anglais regular expression). Les expressions rationnelles sont issues des théories mathématiques des langages formels des années 1940. Leur capacité à décrire"
             "avec concision des ensembles réguliers explique qu’elles se retrouvent dans plusieurs domaines scientifiques dans les années d’après-guerre et justifie leur"
             "adoption en informatique. Les expressions régulières sont aujourd’hui utilisées pour programmer des logiciels avec des fonctionnalités de lecture, de contrôle,"
             "de modification, et d'analyse de textes ainsi que dans la manipulation des langues formelles que sont les langages informatiques."
             "Ces expressions régulières ont la qualité de pouvoir être décrites par des formules ou motifs (en anglais patterns) bien plus simples que les autres moyens2.";
    test::createTestFiles(root, s);
    auto test = "-----BEGIN PRIVATE KEY-----";

    Core::addPath(root);
    Core::addPath("C:/Users/Eloi/Desktop/Projets/SmellsFishy/SmellsFishy/src/test/test_core.cpp");
    Core::addRule(Rule::getRuleSharedPtr(json.getRuleFromDescription("PKCS8 private key")));
    Core::addRule(Rule::getRuleSharedPtr({"r1", "rule1", "([r]\\w+)", 1.0}));
    Core::addRule(Rule::getRuleSharedPtr({"r2", "rule2", "([A-Z]\\w+)", 1.0}));
    auto secrets(Core::getAllSecrets());
    for (const auto &scts : secrets)
    {
        out << "\n\n\t\tTESTING FILE " << scts.file_path << "\n\n";
        for (const auto &sct : scts)
            out << sct.rulePtr->description << "\t" << sct.matchedRegex << '\n';
    }
    test::deleteTestFiles(root);

    return true;
}
