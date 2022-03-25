#include "../../header/test/test.hpp"
#include "../../header/struct/secretsPerFile.hpp"

INIT_LOG

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
    Log::msg << "Rule: testing initRule\n";
    auto _rule = Rule::getRuleSharedPtr({"Good rule",
                                         "Don't use a toaster in a bathtub",
                                         "*insert random symbol*",
                                         5,
                                         2});
    /* START - Testing initRule */
    if (_rule->name != "Good rule")
    {
        Log::err << "Rule: initRule doesn't have the rigth name assigned\n";
        return false;
    }
    if (_rule->description != "Don't use a toaster in a bathtub")
    {
        Log::err << "Rule: initRule doesn't have the rigth description assigned\n";
        return false;
    }
    if (_rule->regex != "*insert random symbol*")
    {
        Log::err << "Rule: initRule doesn't have the rigth regex assigned\n";
        return false;
    }
    if (_rule->maxEntropy != 5)
    {
        Log::err << "Rule: initRule doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if (_rule->minEntropy != 2)
    {
        Log::err << "Rule: initRule doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    Log::msg << "Rule: initRule is working\n";
    _rule->print();
    /********************/
    /*      SECRET      */
    /********************/
    Log::msg << "Secret: testing initSecret\n";
    Secret _test(
        _rule,
        "Wow this texted matched an imaginary regex",
        42,
        8.6);
    /* START - Testing initRule */
    if (_test.rulePtr->name != "Good rule")
    {
        Log::err << "Secret: initSecret doesn't have the rigth name assigned\n";
        return false;
    }
    if (_test.rulePtr->description != "Don't use a toaster in a bathtub")
    {
        Log::err << "Secret: initSecret doesn't have the rigth description assigned\n";
        return false;
    }
    if (_test.rulePtr->regex != "*insert random symbol*")
    {
        Log::err << "Secret: initSecret doesn't have the rigth regex assigned\n";
        return false;
    }
    if (_test.rulePtr->maxEntropy != 5)
    {
        Log::err << "Secret: initSecret doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if (_test.rulePtr->minEntropy != 2)
    {
        Log::err << "Secret: initSecret doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    if (_test.matchedRegex != "Wow this texted matched an imaginary regex")
    {
        Log::err << "Secret: initSecret doesn't have the rigth matchedRegex assigned\n";
        return false;
    }
    if (_test.lineNumber != 42)
    {
        Log::err << "Secret: initSecret doesn't have the rigth lineNumber assigned\n";
        return false;
    }
    if (_test.entropy != 8.6)
    {
        Log::err << "Secret: initSecret doesn't have the rigth entropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    Log::msg << "Secret: initSecret works\n";
    Log::msg << "Secret: testing setSecretEntropy\n";
    /* START - Testing initRule */

    /* END - Testing initRule */
    Log::msg << "Secret: setSecretEntropy is working\n";
    _test.print();
    /********************/
    /* SECRETS PER FILE */
    /********************/
    /* START - Testing initRule */
    Log::msg << "SecretPerFile: testing initSecretsPerFile\n";
    SecretsPerFile _secretsPerFile(
        "./Awsome/test/at/Douai.html");
    if (_secretsPerFile.file_path != "./Awsome/test/at/Douai.html")
    {
        Log::err << "SecretPerFile: initSecretsPerFile doesn't set the rigth file_path\n";
        return false;
    }
    if (_secretsPerFile.secretList.size() != 0)
    {
        Log::err << "SecretPerFile: initSecretsPerFile doesn't have an empty secretList\n";
        return false;
    }
    Log::msg << "SecretPerFile: initSecretsPerFile is working\n";
    /* END - Testing initRule */
    /* START - Testing addSecretPerFile */
    Log::msg << "SecretPerFile: testing addSecretPerFile\n";
    _secretsPerFile.addSecret(_test);
    if (_secretsPerFile.secretList.size() != 1)
    {
        Log::err << "SecretPerFile: addSecretPerFile doesn't add a secret to the secretList\n";
        return false;
    }
    Log::msg << "SecretPerFile: addSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    /* START - Testing addSecretPerFile */
    Log::msg << "SecretPerFile: testing removeSecretPerFile\n";
    _secretsPerFile.removeSecret(0);
    if (_secretsPerFile.secretList.size() != 0)
    {
        Log::err << "SecretPerFile: removeSecretPerFile doesn't remove a secret to the secretList\n";
        return false;
    }
    Log::msg << "SecretPerFile: removeSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    _secretsPerFile.print();
    Log::msg << "Structure: all functions and strucutres are working\n";
    return true;
}