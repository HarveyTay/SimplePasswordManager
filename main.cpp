#include <fstream>
#include <iostream>
#include <vector>

struct Credential
{
    std::string service;
    std::string username;
    std::string password;
};


void loadCredentialDatabase()
{
    std::fstream vaultFile;
    vaultFile.open("vault.csv");
    if (!vaultFile.is_open())
    {
        std::ofstream Database("vault.csv"); //create the database
        Database << "service,username,password\n";
        Database.close();
    }
}

void addCredentialEntryToMem(std::vector<Credential>& creds)
{
    try
    {
        Credential cred;
        std::cout << "What are these credentials for?";
        std::getline(std::cin, cred.service);

        std::cout << "Whats your username for this service?";
        std::getline(std::cin, cred.username);

        std::cout << "Whats your password for this service?";
        std::getline(std::cin, cred.password);

        creds.push_back(cred);
    }
    catch(...)
    {
        std::cout << "Credentials Couldn't Be Appended"; // catch errors
    }

}

int main()
{
    loadCredentialDatabase();

    int sel;
    do
    {
        std::cout << "1. Add Credential\n";
        std::cout << "2. View Credentials\n";
        std::cout << "3. Save and Exit\n";
        std::cout << "Select an option: ";
        std::cin >> sel;
        switch (sel)
            {
            //case 1: (); break;
            default: std::cout << "Choose a valid option\n";
            }
    } while (sel !=1&&sel!=2&&sel!=3);

    return 0;
}