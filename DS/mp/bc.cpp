#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// 🧮 Simple hash function (toy version)
string simpleHash(string input) {
    unsigned long hash = 0;
    int chcnt = 0;
    for (char c : input) {
        hash += (int)c; // Add ASCII value of each character
        chcnt++;
    }
    hash *= chcnt;
    return to_string(hash);
}

class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;
    time_t timestamp;

    Block(int idx, string data, string prevHash) {
        this->index = idx;
        this->data = data;
        this->previousHash = prevHash;
        this->timestamp = time(nullptr);
        this->hash = calculateHash();
    }

    string calculateHash() const {
        return simpleHash(to_string(index) + to_string(timestamp) + data + previousHash);
    }
};

class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        chain.push_back(createGenesisBlock());
    }

    Block createGenesisBlock() {
        return Block(0, "Genesis Block", "0");
    }

    Block getLatestBlock() {
        return chain.back();
    }

    void addBlock(string data) {
        Block newBlock(chain.size(), data, getLatestBlock().hash);
        chain.push_back(newBlock);
    }

    bool isChainValid() {
        for (size_t i = 1; i < chain.size(); i++) {
            Block current = chain[i];
            Block previous = chain[i - 1];

            if (current.hash != current.calculateHash()) {
                cout << "Block " << i << " hash mismatch!" << endl;
                return false;
            }

            if (current.previousHash != previous.hash) {
                cout << " Block " << i << " previous hash mismatch!" << endl;
                return false;
            }
        }
        return true;
    }

    void printBlockchain() {
        for (const auto &block : chain) {
            cout << "Block #" << block.index << "\n";
            cout << " Data: " << block.data << "\n";
            cout << " Hash: " << block.hash << "\n";
            cout << " Prev: " << block.previousHash << "\n";
            cout << "-----------------------------\n";
        }
    }
};

int main() {
    Blockchain bChain;

    bChain.addBlock("Alice pays Bob 10 coins");
    bChain.addBlock("Bob pays Charlie 5 coins");

    cout << "\n Blockchain Contents:\n";
    bChain.printBlockchain();

    cout << "\nIs blockchain valid? " << (bChain.isChainValid() ? "Yes" : "No") << endl;

    // Tamper with the blockchain
    cout << "\n Tampering with a block...\n";
    bChain.chain[1].data = "Alice pays Bob 1000 coins";
    bChain.chain[1].hash = bChain.chain[1].calculateHash(); // Recalculate hash

    cout << "\n Rechecking blockchain validity...\n";
    cout << " Is blockchain valid? " << (bChain.isChainValid() ? "Yes" : "No") << endl;

    return 0;
}
