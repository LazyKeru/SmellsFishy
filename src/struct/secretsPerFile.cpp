#include "../../header/struct/secretsPerFile.hpp"

secretsPerFile::secretsPerFile secretsPerFile::initSecretsPerFile(std::string file_path){
    secretsPerFile res;
    res.file_path = file_path;
    return res;
};

void secretsPerFile::addSecretPerFile(secretsPerFile * secretsPerFile, secret::secret secret){
    secretsPerFile->secretList.push_back(secret);
}

void secretsPerFile::removeSecretPerFile(secretsPerFile * secretsPerFile, int index){
    secretsPerFile->secretList.erase(secretsPerFile->secretList.begin() + index);
}

void secretsPerFile::printSecretsPerFile(const secretsPerFile & secretsPerFile){
    std::cout 
        << "[SecretPerFile] path: " << secretsPerFile.file_path << "\n"
        << " - number of secrets : " << secretsPerFile.secretList.size() << "\n";
}