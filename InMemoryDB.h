//
// Created by Les on 12/4/2023.
//

#ifndef DATAPROCESSINGANDSTORAGE_INMEMORYDB_H
#define DATAPROCESSINGANDSTORAGE_INMEMORYDB_H
#include <string>
#include <map>
#include <optional>
#include <iostream>

using namespace std;

class InMemoryDB
{
    bool transaction = false;
    map<string, int> dataBase;
    map<string, int> buffer;
public:
    optional<int> get(const string& key);
    void put(const string& key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};


#endif //DATAPROCESSINGANDSTORAGE_INMEMORYDB_H
