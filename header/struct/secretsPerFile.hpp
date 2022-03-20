/************************/
/**      Includes      **/
/************************/
#include <string>
#include <vector>
#include <iostream>
#include "./secret.hpp"
/************************/
/**     Functions      **/
/************************/
namespace secretsPerFile
{
    /**
     * @brief Struct of a detected secrets in a file
     * 
     */
    typedef struct secretsPerFile
    {
        std::string file_path;
        std::vector<secret::secret> secretList;
    }secretsPerFile;
    /**
     * @brief init secretPerFile struct
     * 
     * @param file_path path of the analyzed file
     * @return secretPerFile 
     */
    secretsPerFile initSecretsPerFile(
        std::string file_path
    );
    /**
     * @brief add secret to the secretList in the secretPerFile struct
     * 
     * @param secretPerFile the struct secretPerFile for which we want to add a secret
     * @param secret the secret we want to add
     */
    void addSecretPerFile(
        secretsPerFile * secretsPerFile, 
        secret::secret secret
    );
    /**
     * @brief remove secret from secretList in the secretPerFile struct
     * 
     * @param secretPerFile the struct secretPerFile for which we want to remove a secret
     * @param index the index of the we want to remove. As it will simply be used in a loop
     */
    void removeSecretPerFile(
        secretsPerFile * secretsPerFile,
        int index
    );
    /**
     * @brief print the detail of the secretPerFile struct
     * 
     * @param secretsPerFile the struct secretPerFile we want to get info from
     */
    void printSecretsPerFile(const secretsPerFile & secretsPerFile);
} // namespace secret