/************************/
/**      Includes      **/
/************************/
#include <string>
#include <vector>
#include <iostream>
#include "./secret.hpp"
/************************/
/**       Struct       **/
/************************/
/**
 * @brief Class of a detected secrets in a file
 *
 */
struct SecretsPerFile
{
    //// Methods ////

    /**
     * @brief Construct a new Secrets Per File object
     */
    SecretsPerFile();

    /**
     * @brief Construct a new Secrets Per File object
     * 
     * @param filePath path of the analyzed file
     */
    SecretsPerFile(const std::string& filePath);
    /**
     * @brief init secretPerFile struct
     * @param filePath path of the analyzed file
     * @return secretPerFile
     */
    void init(const std::string &filePath);

    /**
     * @brief add secret to the secretList in the secretPerFile struct
     * @param secret the secret we want to add
     */
    void addSecret(const Secret &secret);

    /**
     * @brief remove secret from secretList in the secretPerFile struct
     * @param index the index of the we want to remove. As it will simply be used in a loop
     */
    void removeSecret(int index);

    /**
     * @brief print the detail of the secretPerFile struct
     * @param secretsPerFile the struct secretPerFile we want to get info from
     */
    void print();

    // for-loop related functions
    const Secret& operator[](int index) const;
    std::vector<Secret>::const_iterator begin();
    std::vector<Secret>::const_iterator end();


    //// Variables ////
    std::string file_path;
    std::vector<Secret> secretList;
};