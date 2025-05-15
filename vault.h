#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include "credential.h"

void createCredentialDatabase();
void saveCredentialsToDatabase(std::vector<Credential>& creds);
void addCredentialEntryToMem(std::vector<Credential>& creds);
void loadCredentialDatabase(std::vector<Credential>& creds);
void viewCredentials(std::vector<Credential>& creds);

#endif //VAULT_H
