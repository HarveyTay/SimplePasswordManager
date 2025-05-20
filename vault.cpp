#include <iostream>
#include <fstream>
#include <sstream>

#include "vault.h"


void createCredentialDatabase()
{
    std::fstream vaultFile;
    vaultFile.open("vault.csv");
    if (!vaultFile.is_open())
    {
        std::ofstream Database("vault.csv"); //create the database
        Database << "service,username,password\n";
        Database.close();
        std::cout << "Created database successfully\n";
    }
    std::cout << "Database Loaded :)\n";
}


void saveCredentialsToDatabase(std::vector<Credential>& creds, std::string& key)
{
    try
    {
        std::ofstream vaultFile("vault.csv", std::ios::trunc);

        for (auto& [service, username, password] : creds)
        {
            std::string encryptedService = xorEncryptionDecryption(service, key);
            std::string encryptedUser = xorEncryptionDecryption(username, key);
            std::string encryptedPassword = xorEncryptionDecryption(password, key);
            vaultFile << encryptedService << "," << encryptedUser << "," << encryptedPassword << "\n";
            //std::cout << "data" << encryptedService << encryptedUser << encryptedPassword;
        }

        vaultFile.close();
    }
    catch (...)
    {
        std::cout << "Credentials Couldn't be saved";
    }
}

void addCredentialEntryToMem(std::vector<Credential>& creds)
{
    try
    {
        Credential cred;
        std::cout << "What are these credentials for?";
        std::getline(std::cin, cred.service);//update service
        //std::cout << cred.service << std::endl;
        std::cout << "Whats your username for this service?";
        std::getline(std::cin, cred.username);
        //std::cout << cred.username << std::endl;
        std::cout << "Whats your password for this service?";
        std::getline(std::cin, cred.password);
        //std::cout << cred.password << std::endl;
        creds.push_back(cred);
    }
    catch(...)
    {
        std::cout << "Credential Update Error"; // catch errors
    }

}

void loadCredentialDatabase(std::vector<Credential>& creds, std::string& key)
{
    try{
        std::ifstream vaultFile("vault.csv");
        std::string currLine;
        std::getline(vaultFile, currLine);

        while (std::getline(vaultFile, currLine)){
            std::stringstream ss(currLine);

            Credential cred;


            std::getline(ss, cred.service, ',');
            cred.service = xorEncryptionDecryption(cred.service, key);
            std::getline(ss, cred.username, ',');
            cred.username = xorEncryptionDecryption(cred.username, key);
            std::getline(ss, cred.password, ',');
            cred.password = xorEncryptionDecryption(cred.password, key);

            creds.push_back(cred);

        }
    }catch(...){
    std::cout << "Credential Update Error";
    }
}

void viewCredentials(std::vector<Credential>& creds){
    for (auto& [service, username, password] : creds) {

    std::cout << service << "," << username << "," << password << "\n";
    }
    if (creds.empty()) {
    std::cout << "Nothing stored Yet" << std::endl;
    }
}

std::string xorEncryptionDecryption(const std::string& data, const std::string& key)
{
    if (key.empty())
    {
        std::cout << "Key is empty" << std::endl;
        return "";
    }
    std::string result;

    for (unsigned int i = 0; i < data.length(); i++)
    {
        result += data[i] ^ key[i % key.length()]; //loop with modulus

    }

    return result;
}
