//
// Created by Les on 12/4/2023.
//

#include "InMemoryDB.h"

void InMemoryDB::put(const string &key, int val)
{
    if (!transaction) throw -1;
    buffer[key] = val;
}

void InMemoryDB::begin_transaction()
{
    if (transaction) throw 1;
    transaction = true;
}

void InMemoryDB::commit()
{
    if (!transaction) throw -1;
    dataBase = buffer;
    transaction = false;
}

void InMemoryDB::rollback()
{
    if (!transaction) throw -1;
    transaction = false;
    buffer = dataBase;
}

optional<int> InMemoryDB::get(const string &key)
{
    if (dataBase.find(key) == dataBase.end()) return nullopt;
    return dataBase[key];
}
