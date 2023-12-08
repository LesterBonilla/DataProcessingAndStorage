#include <iostream>
#include "InMemoryDB.h"
#include <regex>

int main()
{
    InMemoryDB inmemoryDB;
    string input;
    bool running = true;

    regex end("End");
    regex help("Help");
    regex get(R"(GET \w+)");
    regex put(R"(PUT \w+ \d+)");
    regex commit(R"(COMMIT)");
    regex rollback(R"(ROLLBACK)");
    regex begin(R"(BEGIN TRANSACTION)");

    cout << R"(Program started. Enter "End" to exit. Enter "Help" for list of commands.)" << endl;

    while (running)
    {
        string argument1;
        string argument2;
        getline(cin, input);
        try
        {
            if (regex_match(input, get))
            {
                argument1 = input.substr(4, input.length() - 1);
                if (inmemoryDB.get(argument1).has_value())
                    cout << inmemoryDB.get(argument1).value() << endl;
            } else if (regex_match(input, put))
            {
                argument1 = input.substr(4, input.find(' ') - 2);
                argument2 = input.substr(input.rfind(' ') + 1, input.length() - 1);
                inmemoryDB.put(argument1, stoi(argument2));
            } else if (regex_match(input, commit))
                inmemoryDB.commit();

            else if (regex_match(input, rollback))
                inmemoryDB.rollback();

            else if (regex_match(input, begin))
                inmemoryDB.begin_transaction();

            else if (regex_match(input, help))
            {
                cout << "Commands: " << endl
                     << "BEGIN TRANSACTION : Begins a transaction to record DB modifications.\n";
                cout << "GET key : Retrieves value of key if it exists." << endl;
                cout << "PUT key value : Requires an open transaction. Updates or adds value of key into DB" << endl;
                cout << "COMMIT : Requires an open transaction. Saves current DB state." << endl;
                cout << "ROLLBACK : Requires an open transaction. Undo all changes made in current transaction."
                     << endl;
                cout
                        << "Note: Keys are restricted to alphanumeric characters and underscore. Values are only integers.\n";
            } else if (regex_match(input, end))
                running = false;

            else cout << "Invalid command. Enter \"Help\" to see list of commands" << endl;
        }
        catch (int err)
        {
            if (err == -1)
                cout << "Error: No open transaction. Exiting program.";
            else
                cout << "Error : There is already on ongoing transaction. Exiting program.";
            return 0;
        }
    }
    return 0;
}
