#pragma once

#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include "credential.h"

void createCredentialDatabase();
void saveCredentialsToDatabase(std::vector<Credential>& creds, std::string key);
void addCredentialEntryToMem(std::vector<Credential>& creds);
void loadCredentialDatabase(std::vector<Credential>& creds, std::string key);
void viewCredentials(std::vector<Credential>& creds);
std::string xorEncryptionDecryption(const std::string& data, const std::string& key);

#endif //VAULT_H
