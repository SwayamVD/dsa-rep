#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Block {
public:
    string data;
    Block* prevHash;
    Block* currHash;
    time_t timestamp;

    Block(string data, Block* prevHash) {
        this->data = data;
        this->prevHash = prevHash;
        this->timestamp = time(nullptr);
        this->currHash = this; // simulate hash with pointer
    }
};

class BlockChain {
public:
    Block* head;
    BlockChain() {
        head = nullptr;
    }

    void addBlock(string data) {
        if (!head) {
            head = new Block(data, nullptr);
        } else {
            Block* newblock = new Block(data, head->currHash);
            head = newblock;
        }
    }

    void printChain() {
        if (!head) {
            cout << "Blockchain is empty.\n";
            return;
        }

        Block* temp = head;
        int index = 0;
        while (temp) {
            cout << "\n\nBlock #" << ++index << endl;
            cout << "Data: " << temp->data << endl;
            cout << "Timestamp: " << ctime(&temp->timestamp);
            cout << "CurrHash (ptr): " << temp->currHash << endl;
            cout << "PrevHash (ptr): " << temp->prevHash << endl;
            cout << "------------------" << endl;
            temp = temp->prevHash;
        }
    }
};

int main() {
    BlockChain bc;
    int choice;
    string data;

    do {
        cout << "\n====== Blockchain Menu ======\n";
        cout << "1. Add Block\n";
        cout << "2. Print Blockchain\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To avoid skipping getline after int input

        switch (choice) {
            case 1:
                cout << "Enter data for the new block: ";
                getline(cin, data);
                bc.addBlock(data);
                cout << "Block added successfully!\n";
                break;

            case 2:
                bc.printChain();
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
