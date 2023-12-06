#include <iostream>
#include "InMemoryDB.h"

int main() {

    InMemoryDB inmemoryDB;

    cout << "get(\"A\")" << endl;
    if (inmemoryDB.get("A").has_value())
        cout << inmemoryDB.get("A").value() << endl;
    else
        cout << "Null" << endl;

    cout << "put(\"A\", 5)" << endl;
    inmemoryDB.put("A", 5);

    cout << "begin_transaction()" << endl;
    inmemoryDB.begin_transaction();

    cout << "put(\"A\", 5)" << endl;
    inmemoryDB.put("A", 5);

    cout << "get(\"A\")" << endl;
    if (inmemoryDB.get("A").has_value())
        cout << inmemoryDB.get("A").value() << endl;
    else
        cout << "Null" << endl;

    cout << "put(\"A\", 6)" << endl;
    inmemoryDB.put("A", 6);

    cout << "commit()" << endl;
    inmemoryDB.commit();

    cout << "get(\"A\")" << endl;
    if (inmemoryDB.get("A").has_value())
        cout << inmemoryDB.get("A").value() << endl;
    else
        cout << "Null" << endl;

    cout << "commit()" << endl;
    inmemoryDB.commit();

    cout << "rollback()" << endl;
    inmemoryDB.rollback();

    cout << "get(\"B\")" << endl;
    inmemoryDB.get("B");

    cout << "begin_transaction()" << endl;
    inmemoryDB.begin_transaction();

    cout << "put(\"B\", 10)" << endl;
    inmemoryDB.put("B", 10);

    cout << "rollback()" << endl;
    inmemoryDB.rollback();

    cout << "get(\"B\")" << endl;
    if (inmemoryDB.get("B").has_value())
        cout << inmemoryDB.get("B").value() << endl;
    else
        cout << "Null" << endl;

    return 0;
}
