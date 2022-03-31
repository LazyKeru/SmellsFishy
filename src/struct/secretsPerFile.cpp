#include "../../header/struct/secretsPerFile.hpp"
#include "../../header/util/log.hpp"

INIT_LOG

SecretsPerFile::SecretsPerFile() 
{
}

SecretsPerFile::SecretsPerFile(const std::string& filePath) :
    file_path(filePath)
{
}

void SecretsPerFile::init(const std::string &filePath)
{
    file_path = filePath;
};

void SecretsPerFile::addSecret(const Secret &secret)
{
    secretList.push_back(secret);
}

void SecretsPerFile::removeSecret(int index)
{
    secretList.erase(secretList.begin() + index);
}

void SecretsPerFile::print()
{
    Log::msg
        << "\n - path: " << file_path << "\n"
        << " - number of secrets : " << secretList.size() << "\n";
}

const Secret &SecretsPerFile::operator[](int index) const
{
    return secretList[index];
}

std::vector<Secret>::const_iterator SecretsPerFile::begin() const
{
    return secretList.begin();
}

std::vector<Secret>::const_iterator SecretsPerFile::end() const
{
    return secretList.end();
}