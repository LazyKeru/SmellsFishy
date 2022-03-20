#include "../../header/test/test.hpp"
#include "../../header/files/fileToString.hpp"
#include "../../header/files/readDir.hpp"
#include "../../header/util/util.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

/**
 * @brief To be written
 *
 * @return true
 * @return false
 */
namespace fs = std::filesystem;

int createTestFiles(const std::string &root, const std::string &stringInFiles)
{

    int numFiles = 0;
    auto condition = []()
    { return randomValue(0u, 10u) < 3; };
    for (int i = 0; i < 100; i++)
    {
        auto depth = randomValue(0u, 6u);
        auto s = root;
        for (auto j = 0; j < depth; j++)
            s += std::string("/") + randomValue('A', 'F');
        if (fs::create_directories(s))
        {
            std::ofstream(s + std::string("/file_") + std::string(".txt")) << stringInFiles;
            numFiles++;
            int k = 0;
            while (condition())
            {
                std::ofstream(s + std::string("/file_") + std::to_string(i + k + numFiles) + std::string(".txt")) << stringInFiles;
                numFiles++;
            }
        }
    }
    return numFiles;
}

void deleteTestFiles(const std::string &path)
{
    fs::remove_all(path);
}

bool test::files()
{
    auto f = __FILE__;
    auto root = "../../FilesTest";
    deleteTestFiles(root);
    auto s = "En informatique, une expression régulière ou expression rationnelle1 ou expression normalenote 1 ou motif est une chaîne de caractères qui décrit,"
             "selon une syntaxe précise, un ensemble de chaînes de caractères possibles. Les expressions régulières sont également appelées regex (un mot-valise formé depuis"
             "l'anglais regular expression). Les expressions rationnelles sont issues des théories mathématiques des langages formels des années 1940. Leur capacité à décrire"
             "avec concision des ensembles réguliers explique qu’elles se retrouvent dans plusieurs domaines scientifiques dans les années d’après-guerre et justifie leur"
             "adoption en informatique. Les expressions régulières sont aujourd’hui utilisées pour programmer des logiciels avec des fonctionnalités de lecture, de contrôle,"
             "de modification, et d'analyse de textes ainsi que dans la manipulation des langues formelles que sont les langages informatiques."
             "Ces expressions régulières ont la qualité de pouvoir être décrites par des formules ou motifs (en anglais patterns) bien plus simples que les autres moyens2.";

    test::log("Loading test environment", f);
    auto n = createTestFiles(root, s);
    auto v = Files::readDirRecursive(root);
    bool result = true;
    test::log("loaded test environment", f);

    if (!Files::isDir(root))
    {
        test::log("The path is not directory", f, test::logType::error);
        result = false;
    }

    test::log("The root path is a directiry", f);
    if (v.size() != n)
    {
        test::log("Not all the wanted files where detected", f, test::logType::error);
        result = false;
    }

    test::log("All the wanted files where detected", f);

    // checking only for one out of numberToSkip documents
    test::log("Checking that fileToString works", f);
    int numberToSkip = 4;
    for (auto i = 0; i < v.size(); ++i)
    {
        auto &path = v[i];
        auto fts = Files::fileToString(path);
        if (i % numberToSkip == 0 && fts != s)
        {
            test::log("error the string in the file, doesn't look like the one we have", f, test::logType::error);
            result = false;
            break;
        }
    }
    test::log("The fileToString works", f);

    deleteTestFiles(root);
    test::log("the files functions are working correctly", f);
    return result;
}