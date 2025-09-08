#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Block class for each transaction block
class Block {
public:
    string sender;
    string receiver;
    string data;
    Block* prevHash;
    Block* transactionid; // Simulated hash (pointer)
    string signature;
    time_t timestamp;

    Block(string sender, string receiver, string data, Block* prevHash, string signature) {
        this->sender = sender;
        this->receiver = receiver;
        this->data = data;
        this->prevHash = prevHash;
        this->timestamp = time(nullptr);
        this->signature = signature;
        this->transactionid = this;
    }
};

// User structure
struct User {
    string name;
    string privatekey;
    string publickey;
    double balance;

    User(string n, string pr, string pb, double ib) {
        this->name = n;
        this->balance = ib;
        this->privatekey = pr;
        this->publickey = pb;
    }
};

// UserDB class to manage users
class UserDB {
protected:
    vector<User> u;

    string generatePublicKey(string s) {
        long key = 1;
        for (char ch : s) {
            key *= (int)ch;
        }
        return to_string(key);
    }

public:
    void createUser() {
        string uname, privatekey, publickey;
        double balance;

        cout << "Enter user name: ";
        cin.ignore();
        getline(cin, uname);

        cout << "Enter user's private key: ";
        getline(cin, privatekey);

        cout << "Enter initial balance: ";
        cin >> balance;

        publickey = generatePublicKey(uname);

        User newUser(uname, privatekey, publickey, balance);
        u.push_back(newUser);

        cout << "\nUser Created Successfully:\n";
        cout << "Name: " << uname << endl;
        cout << "Public Key: " << publickey << endl;
        cout << "Private Key: " << privatekey << endl;
        cout << "Balance: " << balance << endl;
    }

    void displayAllUsers() {
        for (int i = 0; i < u.size(); i++) {
            cout << "User " << i + 1 << ":\n";
            cout << "Name: " << u[i].name << endl;
            cout << "Public Key: " << u[i].publickey << endl;
            cout << "Private Key: " << u[i].privatekey << endl;
            cout << "Balance: " << u[i].balance << endl;
            cout << "-----------------------------\n";
        }
    }

    // Allow Blockchain to access users
    vector<User>& getUsers() {
        return u;
    }
};

// Blockchain class
class BlockChain : public UserDB {
private:
    bool verifyTransaction(string senderkey, string receiverkey, string sign, string data) {
        // Dummy implementation - could be expanded later
        return true;
    }

public:
    Block* head;

    BlockChain() {
        head = nullptr;
    }

    void addBlock(string sender, string receiver, string data, string signature) {
        if (!head) {
            head = new Block(sender, receiver, data, nullptr, signature);
        } else {
            Block* newblock = new Block(sender, receiver, data, head->transactionid, signature);
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
            cout << "\nBlock #" << ++index << endl;
            cout << "Sender: " << temp->sender << endl;
            cout << "Receiver: " << temp->receiver << endl;
            cout << "Data: " << temp->data << endl;
            cout << "Signature: " << temp->signature << endl;
            cout << "Timestamp: " << ctime(&temp->timestamp);
            cout << "CurrHash (ptr): " << temp->transactionid << endl;
            cout << "PrevHash (ptr): " << temp->prevHash << endl;
            cout << "------------------" << endl;
            temp = temp->prevHash;
        }
    }

    void makeTransaction(string sender, string receiver, string data, string signature) {
        vector<User>& users = getUsers();
        bool senderFound = false, receiverFound = false;

        for (int i = 0; i < users.size(); i++) {
            if (users[i].name == sender && users[i].privatekey == signature) {
                senderFound = true;

                for (int j = 0; j < users.size(); j++) {
                    if (users[j].name == receiver) {
                        receiverFound = true;
                        cout << "Processing Transaction from " << sender << " to " << receiver << "...\n";
                        addBlock(sender, receiver, data, signature);
                        cout << "Transaction added to the blockchain.\n";
                        return;
                    }
                }
            }
        }

        if (!senderFound)
            cout << "Transaction failed: Invalid sender credentials!\n";
        else if (!receiverFound)
            cout << "Transaction failed: Receiver not found!\n";
    }
};

// Main function with menu
int main() {
    BlockChain chain;
    int choice;

    do {
        cout << "\n======= Blockchain Menu =======\n";
        cout << "1. Create User\n";
        cout << "2. Make Transaction\n";
        cout << "3. Print Blockchain\n";
        cout << "4. Show All Users\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                chain.createUser();
                break;
            case 2: {
                string sender, receiver, data, privatekey;
                cout << "Enter Sender Name: ";
                cin >> sender;
                cout << "Enter Receiver Name: ";
                cin >> receiver;
                cout << "Enter Transaction Data: ";
                cin.ignore();
                getline(cin, data);
                cout << "Enter Sender's Private Key: ";
                cin >> privatekey;
                chain.makeTransaction(sender, receiver, data, privatekey);
                break;
            }
            case 3:
                chain.printChain();
                break;
            case 4:
                chain.displayAllUsers();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
