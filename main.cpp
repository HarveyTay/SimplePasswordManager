#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>

struct Credential
{
    std::string service;
    std::string username;
    std::string password;
};


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


void saveCredentialsToDatabase(std::vector<Credential>& creds)
{
    try
    {
        std::ofstream vaultFile("vault.csv", std::ios::trunc);

        for (const auto& [service, username, password] : creds)
        {
            vaultFile << service << "," << username << "," << password << "\n";
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

        std::cout << "Whats your username for this service?";
        std::getline(std::cin, cred.username);

        std::cout << "Whats your password for this service?";
        std::getline(std::cin, cred.password);

        creds.push_back(cred);
    }
    catch(...)
    {
        std::cout << "Credential Update Error"; // catch errors
    }

}

void loadCredentialDatabase(std::vector<Credential>& creds)
{
    try{
        std::ifstream vaultFile("vault.csv");
        std::string currLine;

        while (std::getline(vaultFile, currLine)){
            std::stringstream ss(currLine);

            Credential cred;

            std::getline(ss, cred.service, ',');
            std::getline(ss, cred.username, ',');
            std::getline(ss, cred.password, ',');

            creds.push_back(cred);

        }
    }catch(...){
    std::cout << "Credential Update Error";
    }
}

void viewCredentials(std::vector<Credential>& creds){
    for (const auto& [service, username, password] : creds) {
    std::cout << service << "," << username << "," << password << "\n";
    }
    if (creds.empty()) {
    std::cout << "Nothing stored Yet" << std::endl;
    }
}

int main()
{
    std::vector<Credential> creds;

    createCredentialDatabase();
    loadCredentialDatabase(creds);

    int sel;
    do
    {
        std::cout << "1. Add Credential\n";
        std::cout << "2. View Credentials\n";
        std::cout << "3. Save and Exit\n";
        std::cout << "Select an option: ";
        std::cin >> sel;
        std::cin.ignore();
        switch (sel)
            {
            case 1: addCredentialEntryToMem(creds); break;
            case 2: viewCredentials(creds); break;
            default: std::cout << "Choose a valid option\n";
            }
    } while (sel!=3);

    saveCredentialsToDatabase(creds);

    return 0;
}