#include "../../header/test/test.hpp"
#include "../../header/struct/secretsPerFile.hpp"
/**
 * @brief To be written
 *
 * @return true
 * @return false
 */

bool test::structure()
{
    /********************/
    /*       RULE       */
    /********************/
    std::cout << "[Structure - Rule] log: testing initRule\n";
    auto _rule = Rule::getRuleSharedPtr({"Good rule",
                                         "Don't use a toaster in a bathtub",
                                         "*insert random symbol*",
                                         5,
                                         2});
    /* START - Testing initRule */
    if (_rule->name != "Good rule")
    {
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth name assigned\n";
        return false;
    }
    if (_rule->description != "Don't use a toaster in a bathtub")
    {
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth description assigned\n";
        return false;
    }
    if (_rule->regex != "*insert random symbol*")
    {
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth regex assigned\n";
        return false;
    }
    if (_rule->maxEntropy != 5)
    {
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if (_rule->minEntropy != 2)
    {
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    std::cout << "[Structure - Rule] log: initRule is working\n";
    _rule->print();
    /********************/
    /*      SECRET      */
    /********************/
    std::cout << "[Structure - Secret] log: testing initSecret\n";
    Secret _test(
        _rule,
        "Wow this texted matched an imaginary regex",
        42,
        8.6);
    /* START - Testing initRule */
    if (_test.rulePtr->name != "Good rule")
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth name assigned\n";
        return false;
    }
    if (_test.rulePtr->description != "Don't use a toaster in a bathtub")
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth description assigned\n";
        return false;
    }
    if (_test.rulePtr->regex != "*insert random symbol*")
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth regex assigned\n";
        return false;
    }
    if (_test.rulePtr->maxEntropy != 5)
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if (_test.rulePtr->minEntropy != 2)
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    if (_test.matchedRegex != "Wow this texted matched an imaginary regex")
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth matchedRegex assigned\n";
        return false;
    }
    if (_test.lineNumber != 42)
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth lineNumber assigned\n";
        return false;
    }
    if (_test.entropy != 8.6)
    {
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth entropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    std::cout << "[Structure - Secret] log: initSecret works\n";
    std::cout << "[Structure - Secret] log: testing setSecretEntropy\n";
    /* START - Testing initRule */

    /* END - Testing initRule */
    std::cout << "[Structure - Secret] log: setSecretEntropy is working\n";
    _test.print();
    /********************/
    /* SECRETS PER FILE */
    /********************/
    /* START - Testing initRule */
    std::cout << "[Structure - SecretPerFile] log: testing initSecretsPerFile\n";
    SecretsPerFile _secretsPerFile(
        "./Awsome/test/at/Douai.html");
    if (_secretsPerFile.file_path != "./Awsome/test/at/Douai.html")
    {
        std::cout << "[Structure - SecretPerFile] Error: initSecretsPerFile doesn't set the rigth file_path\n";
        return false;
    }
    if (_secretsPerFile.secretList.size() != 0)
    {
        std::cout << "[Structure - SecretPerFile] Error: initSecretsPerFile doesn't have an empty secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: initSecretsPerFile is working\n";
    /* END - Testing initRule */
    /* START - Testing addSecretPerFile */
    std::cout << "[Structure - SecretPerFile] log: testing addSecretPerFile\n";
    _secretsPerFile.addSecret(_test);
    if (_secretsPerFile.secretList.size() != 1)
    {
        std::cout << "[Structure - SecretPerFile] Error: addSecretPerFile doesn't add a secret to the secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: addSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    /* START - Testing addSecretPerFile */
    std::cout << "[Structure - SecretPerFile] log: testing removeSecretPerFile\n";
    _secretsPerFile.removeSecret(0);
    if (_secretsPerFile.secretList.size() != 0)
    {
        std::cout << "[Structure - SecretPerFile] Error: removeSecretPerFile doesn't remove a secret to the secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: removeSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    _secretsPerFile.print();
    std::cout << "[Structure] log: all functions and strucutres are working\n";
    return true;
}