#include<iostream>
#include<vector>
#include<ctime>
#include<functional>
using namespace std;



//simple hashing function but has less security
string generateHash(string ustr){
    unsigned long hash = 0;
    for(int i=0;i<ustr.length();i++){
        hash = hash * 31 + ustr[i];
    }
    return to_string(hash);
}

//stl hashing function
// string generateHash(string ustr){
//     hash<string> str_hash;
//     string hashval = to_string(str_hash(ustr));
//     return hashval;
// }


struct Block{
    int bind;
    string sender;
    string receiver;
    double data;
    Block* prev;
    string signature;
    time_t timestamp;
    string currblockhash;
    string prevblockhash;
    
    Block(string sender, string receiver, double data,Block* prev, string signature ,int bind,string prevblockhash) {
        this->bind = bind;
        this->sender = sender;
        this->receiver = receiver;
        this->data = data;
        this->prev = prev;
        this->timestamp = time(nullptr);
        this->signature = signature;
        string ustr =  sender + receiver + to_string(data) + signature+ to_string(this->timestamp);
        this->currblockhash = generateHash(ustr);
        this->prevblockhash = prevblockhash;
    }
};

class User {
    public:
        string name;
        string signature;
        string publickey;
        double balance;
        User* next;
    
        User(string n, string s, string pk, double b) {
            name = n;
            signature = s;
            publickey = pk;
            balance = b;
            next = nullptr;
        }
    };
    

class UserManager {
    public:
        User* headu;
    
        UserManager() {
            headu = nullptr;
        }
    
        // Create a public key
        string generatePublicKey(string uname, string sign) {
            string s = uname + sign;
            long sd = 2;
            for (int i = 0; i < s.length(); i++) {
                sd += (int)s[i];
            }
            return to_string(sd * 10);
        }
    
        // Create user
        void createUser(string uname, string sign, double bal) {
            string publickey = generatePublicKey(uname, sign);
            User* n = new User(uname, sign, publickey, bal);
            if (!headu) {
                headu = n;
            } else {
                User* temp = headu;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = n;
            }
        }
    
        bool isValidUser(string pubkey) {
            User* temp = headu;
            while (temp) {
                if (temp->publickey == pubkey) return true;
                temp = temp->next;
            }
            return false;
        }
        
        bool verifySignature(string pubkey, string sign) {
            User* temp = headu;
            while (temp) {
                if (temp->publickey == pubkey && temp->signature == sign) return true;
                temp = temp->next;
            }
            return false;
        }
        
        bool hasSufficientBalance(string pubkey, double amount) {
            User* temp = headu;
            while (temp) {
                if (temp->publickey == pubkey) return temp->balance >= amount;
                temp = temp->next;
            }
            return false;
        }
        
        void transferBalance(string sender, string receiver, double amount) {
            User* temp = headu;
            User* senderUser = nullptr;
            User* receiverUser = nullptr;
        
            while (temp) {
                if (temp->publickey == sender) senderUser = temp;
                if (temp->publickey == receiver) receiverUser = temp;
                temp = temp->next;
            }
        
            if (senderUser && receiverUser) {
                senderUser->balance -= amount;
                receiverUser->balance += amount;
            }
        }
        
    
        // Display all users
        void displayAllUsers() {
            if (!headu) {
                cout << "No Users Available" << endl;
                return;
            }
            User* temp = headu;
            int count = 1;
            while (temp) {
                cout << "\n-----------------------------\n";
                cout << "User " << count++ << ":\n";
                cout << "Name: " << temp->name << endl;
                cout << "Public Key: " << temp->publickey << endl;
                cout << "Private Key: " << temp->signature << endl;
                cout << "Balance: " << temp->balance << endl;
                cout << "-----------------------------\n";
                temp = temp->next;
            }
        }

    };
    

class Blockchain: public UserManager{
    public:
    Block* head;
    int bind = 0;
    Blockchain(){
        head = nullptr;
    }
    void addBlock(string sender, string receiver, double data, string signature) {
        if (!head) {
            head = new Block(sender, receiver, data, nullptr, signature , ++bind , "0");
        } else {
            Block* newblock = new Block(sender,receiver,data,head,signature , ++bind , head->currblockhash);
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
            if(temp->prev == nullptr || temp->prevblockhash == temp->prev->currblockhash){
                cout << "\n------------------" << endl;
                cout << "Block #" << temp->bind << endl;
                cout << "Sender: " << temp->sender << endl;
                cout << "Receiver: " << temp->receiver << endl;
                cout << "Amount: " << temp->data << endl;
                cout << "Timestamp: " << ctime(&temp->timestamp);
                cout << "Block Hash: " << temp->currblockhash << endl;
                cout << "Prev Block Hash: " << temp->prevblockhash << endl;
                cout << "------------------" << endl;
                temp = temp->prev;
            }
            else{
                cout<<"Someone is tring to tamper the Blockchain !!"<<endl;
                return;
            }
        }
    }

    void makeTransaction(string sender, string receiver, double data, string sign) {
        if (isValidUser(receiver) && verifySignature(sender, sign) && hasSufficientBalance(sender, data)) {
            cout << "\nProcessing Transaction from " << sender << " to " << receiver << "...\n";
            transferBalance(sender, receiver, data);  
            addBlock(sender, receiver, data, sign);  
            cout << "Transaction added to the blockchain.\n";
        } else {
            cout << "Transaction failed due to incorrect credentials or insufficient balance!" << endl;
        }
    }
    

    void updateBlock(int bi){
        Block* temp = head;
        while (temp) {
            if(temp->bind == bi){
                double data;
                cout<<"Try to change the Ammount (current ammount is "<< temp->data <<"): ";
                cin.ignore();
                cin>>data;
                temp->data = data;
                temp->timestamp = time(nullptr);
                string ustr =  temp->sender + temp->receiver + to_string(temp->data) + temp->signature + to_string(temp->timestamp);
                temp->currblockhash = generateHash(ustr);
            }
            temp = temp->prev;
        }
    }
    
    void menu() {
        int choice;
        string name, signature, sender, receiver,  sign;
        double data;
        double balance;
        int blockIndex;
        while (true) {
            cout << "\n--- Blockchain Menu ---\n";
            cout << "1. Create User\n";
            cout << "2. Make Transaction\n\n";
            cout << "3. List All Users\n";
            cout << "4. Show Blockchain\n\n";
            cout << "5. Update Transaction (Corrupts Blockchain !)\n";
            cout << "6. Exit\n";
            cout << "-----------------------\n\n";
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
                    cout << "Enter Ammount: ";
                    cin >> data;
                    cout << "Enter Signature: ";
                    cin.ignore();
                    getline(cin, sign);
                    makeTransaction(sender, receiver, data, sign);
                    break;

                case 5:
                    cout << "Enter Block Index to Update: ";
                    cin >> blockIndex;
                    updateBlock(blockIndex);
                    break;

                case 3:
                    displayAllUsers();
                    break;

                case 4:
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

int main(){
    Blockchain b;
    b.menu();
    return 0;
}