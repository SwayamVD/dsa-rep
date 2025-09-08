#include<iostream>
#include<string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

class ExpressionTree {
public:
    Node* root;
    ExpressionTree(){
        root = nullptr;
    }
    int evaluate(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            return stoi(root->data);
        }
        int lval = evaluate(root->left);
        int rval = evaluate(root->right);
        if(root->data == "+"){
            return lval+rval;
        }
        if(root->data == "-"){
            return lval-rval;
        }
        if(root->data == "*"){
            return lval*rval;
        }
        if(root->data == "/"){
            return lval/rval;
        }
        return 0;
    }
};
