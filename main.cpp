#include <fstream>
#include <iostream>

void CreatePasswordDatabase()
{
    std::ofstream passwordDatabase("passwords.txt");
}

void AddPasswordToDatabase(const std::string& Credential)
{
    try
    {
        std::ifstream passwordDatabase("passwords.txt");
        passwordDatabase.open("passwords.txt");

        passwordDatabase << (operator<<(std::cout, Credential), "\n");
    }
    catch(...)
    {
        std::cout << "Credentials Couldn't Be Appended";
    }

}

int main()
{

}