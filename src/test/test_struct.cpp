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
    std::shared_ptr<rule::rule> _rule = rule::initRule(
        "Good rule",
        "Don't use a toaster in a bathtub",
        "*insert random symbol*",
        5,
        2
    );
    /* START - Testing initRule */
    if(_rule.get()->name!="Good rule"){
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth name assigned\n";
        return false;
    }
    if(_rule.get()->description!="Don't use a toaster in a bathtub"){
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth description assigned\n";
        return false;
    }
    if(_rule.get()->regex!="*insert random symbol*"){
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth regex assigned\n";
        return false;
    }
    if(_rule.get()->maxEntropy!=5){
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if(_rule.get()->minEntropy!=2){
        std::cout << "[Structure - Rule] Error: initRule doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    std::cout << "[Structure - Rule] log: initRule is working\n";
    rule::printRule(_rule);
    /********************/
    /*      SECRET      */
    /********************/
    std::cout << "[Structure - Secret] log: testing initSecret\n";
    secret::secret _test = secret::initSecret(
        _rule,
        "Wow this texted matched an imaginary regex",
        42,
        8.6
    );
    /* START - Testing initRule */
    if(_test.rule_ptr.get()->name!="Good rule"){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth name assigned\n";
        return false;
    }
    if(_test.rule_ptr.get()->description!="Don't use a toaster in a bathtub"){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth description assigned\n";
        return false;
    }
    if(_test.rule_ptr.get()->regex!="*insert random symbol*"){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth regex assigned\n";
        return false;
    }
    if(_test.rule_ptr.get()->maxEntropy!=5){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth maxEntropy assigned\n";
        return false;
    }
    if(_test.rule_ptr.get()->minEntropy!=2){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth minEntropy assigned\n";
        return false;
    }
    if(_test.matchedRegex!="Wow this texted matched an imaginary regex"){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth matchedRegex assigned\n";
        return false;
    }
    if(_test.lineNumbre!=42){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth lineNumber assigned\n";
        return false;
    }
    if(_test.entropy!=8.6){
        std::cout << "[Structure - Secret] Error: initSecret doesn't have the rigth entropy assigned\n";
        return false;
    }
    /* END - Testing initRule */
    std::cout << "[Structure - Secret] log: initSecret works\n";
    std::cout << "[Structure - Secret] log: testing setSecretEntropy\n";
    /* START - Testing initRule */
    secret::setSecretEntropy(&_test, 6.9);
    if(_test.entropy!=6.9){
        std::cout << "[Structure - Secret] Error: setSecretEntropy doesn't set the rigth entropy\n";
        return false;
    }
    /* END - Testing initRule */
    std::cout << "[Structure - Secret] log: setSecretEntropy is working\n";
    secret::printSecret(_test);
    /********************/
    /* SECRETS PER FILE */
    /********************/
    /* START - Testing initRule */
    std::cout << "[Structure - SecretPerFile] log: testing initSecretsPerFile\n";
    secretsPerFile::secretsPerFile _secretsPerFile = secretsPerFile::initSecretsPerFile(
        "./Awsome/test/at/Douai.html"
    );
    if(_secretsPerFile.file_path!="./Awsome/test/at/Douai.html"){
        std::cout << "[Structure - SecretPerFile] Error: initSecretsPerFile doesn't set the rigth file_path\n";
        return false;
    }
    if(_secretsPerFile.secretList.size()!=0){
        std::cout << "[Structure - SecretPerFile] Error: initSecretsPerFile doesn't have an empty secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: initSecretsPerFile is working\n";
    /* END - Testing initRule */
    /* START - Testing addSecretPerFile */
    std::cout << "[Structure - SecretPerFile] log: testing addSecretPerFile\n";
    secretsPerFile::addSecretPerFile(&_secretsPerFile,_test);
    if(_secretsPerFile.secretList.size()!=1){
        std::cout << "[Structure - SecretPerFile] Error: addSecretPerFile doesn't add a secret to the secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: addSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    /* START - Testing addSecretPerFile */
    std::cout << "[Structure - SecretPerFile] log: testing removeSecretPerFile\n";
    secretsPerFile::removeSecretPerFile(&_secretsPerFile, 0);
    if(_secretsPerFile.secretList.size()!=0){
        std::cout << "[Structure - SecretPerFile] Error: removeSecretPerFile doesn't remove a secret to the secretList\n";
        return false;
    }
    std::cout << "[Structure - SecretPerFile] log: removeSecretPerFile is working\n";
    /* END - Testing addSecretPerFile */
    secretsPerFile::printSecretsPerFile(_secretsPerFile);
    std::cout << "[Structure] log: all functions and strucutres are working\n";
    return true;
}