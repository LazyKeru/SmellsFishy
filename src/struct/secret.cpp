#include "../../header/struct/secret.hpp"

secret::secret secret::initSecret(std::shared_ptr<rule::rule> rule_ptr, std::string matchedRegex, int lineNumbre, double entropy){
        secret res;
        res.rule_ptr = rule_ptr;
        res.matchedRegex = matchedRegex;
        res.lineNumbre = lineNumbre;
        res.entropy = entropy;
        return res;
}

void secret::setSecretEntropy(secret *secret, double newEntropy){
    secret->entropy = newEntropy;
}

void secret::printSecret(const secret & secret){
    std::cout 
        << "[Detected Secret] " << secret.matchedRegex << "\n"
        << " - Broken rule : " << secret.rule_ptr.get()->name << "\n"
        << " - lineNumber : " << secret.lineNumbre << "\n"
        << " - entropy : " << secret.entropy << "\n";
}

