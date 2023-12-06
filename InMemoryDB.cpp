//
// Created by Les on 12/4/2023.
//

#include "InMemoryDB.h"

void InMemoryDB::put(const string& key, int val)
{
    if (!transaction) cout << "Error: transaction is not in progress." << endl;
    buffer[key] = val;
}

void InMemoryDB::begin_transaction()
{
    if (transaction) return;
    transaction = true;
}

void InMemoryDB::commit()
{
    if (!transaction) cout << "Error: No open transaction." << endl;
    dataBase = buffer;
    transaction = false;
}

void InMemoryDB::rollback()
{
    if (!transaction) cout << "Error: No ongoing transaction." << endl;
    buffer = dataBase;
}

optional<int> InMemoryDB::get(const string& key)
{
    if (dataBase.find(key) == dataBase.end()) return nullopt;
    return dataBase[key];
}
