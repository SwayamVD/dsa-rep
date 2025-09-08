#include<iostream>
#include<ctime>
#include<string>
#include<functional>
using namespace std;

//block structure
class Block{
    private:

    //hashing functions
    string generateHash1(int i,string d,string ph,time_t t){
        string ls = to_string(i) + d + ph + to_string(t);
        unsigned long h=0;
        for(int i=0;i<ls.length();i++){
            h = (h * 31) + ls[i];
        }
        return to_string(h);
    }

    public:

    int index;
    string data;
    string prevHash;
    string Hash;
    time_t timestamp;
    //string nonce;
    Block* prev;
    
    Block(int i,string d,string ph){
        this->index = i;
        this->data = d;
        this->prevHash = ph;
        this->timestamp = time(nullptr);
        this->Hash = generateHash1(i,d,ph,this->timestamp);
    }
};

class Blockchain{
    public:
    Block* head;
    Blockchain(){
        head = nullptr;
    }

    void addblock(int i,string d){
        string ph;
        if(!head){
            ph = "00";
        }
        else{
            ph = head->Hash;
        }
        Block* n = new Block(i,d,ph);
        n->prev = head;
        head = n;
    }

    void displayblock(){
        Block* temp = head;
        while(temp){
            if(temp->prev)
            cout << "Index: " << temp->index << endl;
            cout << "Data: " << temp->data << endl;
            cout << "Previous Hash: " << temp->prevHash << endl;
            cout << "Hash: " << temp->Hash << endl;
            cout << "Timestamp: " << ctime(&temp->timestamp);
            cout << "-----------------------------"<< temp << endl;
            temp = temp->prev;
        }
    }
};

int main(){
    Blockchain b1;
    b1.addblock(1,"swyasd sdfsks sdfklsdk lskdflsd");
    b1.addblock(2,"dslkjf;lsdkf");
    b1.addblock(3,"sdfsdfsddkf");
    b1.addblock(4,"dsdfsdfsdfsdkf");
    b1.displayblock();
}