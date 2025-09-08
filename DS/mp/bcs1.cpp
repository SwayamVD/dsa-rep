// first version on blockchain simulation using cpp


#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class Block{
    public:
    string data;
    Block* prevHash;
    Block* currHash;
    time_t timestamp;

    Block(string data, Block* prevHash){
        this->data = data;
        this->prevHash = prevHash;
        this->timestamp = time(nullptr);
        this->currHash = this;
    }
};

class BlockChain{
    public:
    //b1 <- b2 <- b3(head)
    Block* head;
    BlockChain(){
        head = nullptr;
    }

    void addBlock(string data){
        if(!head){
            head = new Block(data, nullptr);
        }
        else{
            Block* newblock = new Block(data,head->currHash);
            head = newblock;
        }
    }
    
    void printChain() {
        Block* temp = head;
        while (temp) {
            cout << "Data: " << temp->data << endl;
            cout << "Timestamp: " << temp->timestamp << endl;
            cout << "CurrHash (ptr): " << temp->currHash << endl;
            cout << "PrevHash (ptr): " << temp->prevHash << endl;
            cout << "------------------" << endl;
            temp = temp->prevHash;
        }
    }
};

int main(){
    BlockChain bc;
    bc.addBlock("Genesis Block");
    bc.addBlock("Second Block");
    bc.addBlock("Third Block");

    bc.printChain();
    return 0;
}