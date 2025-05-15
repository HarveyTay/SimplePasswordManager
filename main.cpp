#include <fstream>
#include <iostream>
#include <vector>

#include "vault.cpp"


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