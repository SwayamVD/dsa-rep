#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

const int TABLE_SIZE = 128;

class hashEntry {
public:
    int key;
    int value;
    hashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class hashMap {
public:
    hashEntry **table;

    hashMap() {
        table = new hashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hashfun(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int hash = hashfun(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashfun(hash + 1);
        }

        if (table[hash] != NULL) {
            table[hash]->value = value;
        } else {
            table[hash] = new hashEntry(key, value);
        }
    }

    int Search(int key) {
        int hash = hashfun(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = hashfun(hash + 1);
        }
        if (table[hash] == NULL) {
            return -1;
        } else {
            return table[hash]->value;
        }
    }

    void Remove(int key) {
        int hash = hashfun(key);
        while (table[hash] != NULL) {
            if (table[hash]->key == key) {
                delete table[hash];
                table[hash] = NULL;
                cout << "Element Deleted" << endl;
                return;
            }
            hash = hashfun(hash + 1);
        }
        cout << "No Element found at key " << key << endl;
    }


    void displayTable() {
        cout << "Hash Table Contents:" << endl;
        bool empty = true;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                cout << "Key: " << table[i]->key << ", Value: " << table[i]->value << endl;
                empty = false;
            }
        }
        if (empty) {
            cout << "Hash Table is empty!" << endl;
        }
    }

    ~hashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL)
                delete table[i];
        }
        delete[] table;
    }
};
int main() {
    hashMap hash;
    int key, value;
    int choice;
    int result;

    while (1) {
        cout << "1. Insert element into the table" << endl;
        cout << "2. Search element from the key" << endl;
        cout << "3. Delete element at a key" << endl;
        cout << "4. Display hash table contents" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            hash.insert(key, value);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            result = hash.Search(key);
            if (result == -1) {
                cout << "No element found at key " << key << endl;
            } else {
                cout << "Element at key " << key << " : " << result << endl;
            }
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            hash.Remove(key);
            break;

        case 4:
            hash.displayTable();
            break;

        case 5:
            exit(0);

        default:
            cout << "\nEnter a valid option\n";
        }
    }

    return 0;
}

