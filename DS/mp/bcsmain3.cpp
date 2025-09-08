#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<functional>
using namespace std;

string generateHash(string ustr) {
    unsigned long hash = 0;
    for (int i = 0; i < ustr.length(); i++) {
        hash = hash * 31 ^ ustr[i];
    }
    return to_string(hash);
}

struct Block {
    int bind;
    string sender;
    string receiver;
    string data;
    Block* prev;
    Block* curr;
    string signature;
    time_t timestamp;
    string currblockhash;
    string prevblockhash;

    Block(string sender, string receiver, string data, Block* prevHash, string signature, int bind, string prevblockhash) {
        this->bind = bind;
        this->sender = sender;
        this->receiver = receiver;
        this->data = data;
        this->prev = prevHash;
        this->timestamp = time(nullptr);
        this->signature = signature;
        this->curr = this;
        string ustr = sender + receiver + data + signature + to_string(this->timestamp);
        this->currblockhash = generateHash(ustr);
        this->prevblockhash = prevblockhash;
    }
};

struct User {
    string name;
    string publickey;
    string signature;
    double balance;

    User(string n, string pr, string pb, double ib) {
        this->name = n;
        this->balance = ib;
        this->signature = pr;
        this->publickey = pb;
    }
};

class UserManager {
public:
    vector<User> u;

    void createUser(string uname, string sign, double bal) {
        string publickey = generatePublicKey(uname, sign);
        User nu(uname, sign, publickey, bal);
        u.push_back(nu);
    }

    string generatePublicKey(string uname, string sign) {
        string s = uname + sign;
        long sd = 2;
        for (int i = 0; i <= s.length(); i++) {
            sd += (int)s[i];
        }
        return to_string(sd * 10);
    }

    int verifyUser(string pubkey) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i].publickey == pubkey) {
                return 1;
            }
        }
        return 0;
    }

    int verifyUser(string pubkey, string sign) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i].publickey == pubkey && u[i].signature == sign) {
                return 1;
            }
        }
        return 0;
    }

    void displayAllUsers() {
        for (int i = 0; i < u.size(); i++) {
            cout << "\n-----------------------------\n";
            cout << "User " << i + 1 << ":\n";
            cout << "Name: " << u[i].name << endl;
            cout << "Public Key: " << u[i].publickey << endl;
            cout << "Private Key: " << u[i].signature << endl;
            cout << "Balance: " << u[i].balance << endl;
            cout << "-----------------------------\n";
        }
    }
};

class Blockchain : public UserManager {
public:
    Block* head;
    int bind = 0;
    Blockchain() {
        head = nullptr;
    }

    void addBlock(string sender, string receiver, string data, string signature) {
        if (!head) {
            head = new Block(sender, receiver, data, nullptr, signature, ++bind, "0");
        } else {
            Block* newblock = new Block(sender, receiver, data, head->curr, signature, ++bind, head->currblockhash);
            head = newblock;
        }
    }

    void printChain() {
        if (!head) {
            cout << "Blockchain is empty.\n";
            return;
        }

        Block* temp = head;
        while (temp) {
            if (temp->prev == nullptr || temp->prevblockhash == temp->prev->currblockhash) {
                cout << "\n------------------" << endl;
                cout << "Block #" << temp->bind << endl;
                cout << "Sender: " << temp->sender << endl;
                cout << "Receiver: " << temp->receiver << endl;
                cout << "Data: " << temp->data << endl;
                cout << "Signature: " << temp->signature << endl;
                cout << "Timestamp: " << ctime(&temp->timestamp);
                cout << "Block Hash: " << temp->currblockhash << endl;
                cout << "Prev Block Hash: " << temp->prevblockhash << endl;
                cout << "------------------" << endl;
                temp = temp->prev;
            } else {
                cout << "Blockchain has been corrupted!!";
                return;
            }
        }
    }

    void makeTransaction(string sender, string receiver, string data, string sign) {
        if (verifyUser(sender, sign) && verifyUser(receiver)) {
            cout << "\nProcessing Transaction from " << sender << " to " << receiver << "...\n";
            addBlock(sender, receiver, data, sign);
            cout << "Transaction added to the blockchain.\n";
        } else {
            cout << "Transaction failed due to incorrect Credentials!" << endl;
        }
    }

    void updateBlock(int bi) {
        Block* temp = head;
        while (temp) {
            if (temp->bind == bi) {
                string data;
                cout << "Enter new Data: ";
                cin.ignore();
                getline(cin, data);
                temp->data = data;
                temp->timestamp = time(nullptr);
                string ustr = temp->sender + temp->receiver + temp->data + temp->signature + to_string(temp->timestamp);
                temp->currblockhash = generateHash(ustr);
            }
            temp = temp->prev;
        }
    }

    void menu() {
        int choice;
        string name, signature, sender, receiver, data, sign;
        double balance;
        int blockIndex;
        while (true) {
            cout << "\n--- Blockchain Menu ---\n";
            cout << "1. Create User\n";
            cout << "2. Make Transaction\n";
            cout << "3. Update Transaction\n";
            cout << "4. List All Users\n";
            cout << "5. Show Blockchain\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter Name: ";
                    getline(cin, name);
                    cout << "Enter Signature: ";
                    getline(cin, signature);
                    cout << "Enter Balance: ";
                    cin >> balance;
                    createUser(name, signature, balance);
                    break;

                case 2:
                    cout << "Enter Sender Public Key: ";
                    cin >> sender;
                    cout << "Enter Receiver Public Key: ";
                    cin >> receiver;
                    cin.ignore();
                    cout << "Enter Data: ";
                    getline(cin, data);
                    cout << "Enter Signature: ";
                    getline(cin, sign);
                    makeTransaction(sender, receiver, data, sign);
                    break;

                case 3:
                    cout << "Enter Block Index to Update: ";
                    cin >> blockIndex;
                    updateBlock(blockIndex);
                    break;

                case 4:
                    displayAllUsers();
                    break;

                case 5:
                    printChain();
                    break;

                case 6:
                    cout << "Exiting program...\n";
                    return;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    Blockchain b;
    b.menu();
    return 0;
}
