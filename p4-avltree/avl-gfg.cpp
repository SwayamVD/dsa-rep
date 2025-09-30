#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    int ht;
    node(int data){
        this->data = data;
        left = right = nullptr;
        ht = 1;
    }
};

class avl{
    public:
    node* root;
    avl(){
        root = nullptr;
    }
    int height(node* t);
    int balance(node* t);
    node* rotate_right(node* x);
    node* rotate_left(node* x);
    node* insert(node* x,int key);
    void preorder(node* x);
    void inorder(node* x);
};

int avl::height(node* t){
    if(t==NULL) return 0;
    return 1 + max(height(t->left),height(t->right));
}

int avl::balance(node* t){
    if(t==NULL) return 0;
    return height(t->left) - height(t->right);
}

node* avl::rotate_right(node* x){
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = 1 + max(height(x->left), height(x->right));
    y->ht = 1 + max(height(y->left), height(y->right));
    return y;
}

node* avl::rotate_left(node* x){
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = 1 + max(height(x->left), height(x->right));
    y->ht = 1 + max(height(y->left), height(y->right));
    return y;
}

node* avl::insert(node* x,int key){
    if(x==nullptr){
        return new node(key);
    }

    if(key < x->data){
        x->left = insert(x->left,key);
    }
    else if(key > x->data){
        x->right = insert(x->right,key);
    }
    else{
        return x;
    }

    x->ht = 1 + max(height(x->left),height(x->right));
    int bal = balance(x);

    //ll
    if(bal > 1 && key < x->left->data){
        return rotate_right(x);
    }
    //rr
    if(bal < -1 && key > x->right->data){
        return rotate_left(x);
    }
    //rl
    if(bal < -1 && key < x->right->data){
        x->right = rotate_right(x->right);
        return rotate_left(x);
    }
    //lr
    if(bal > 1 && key > x->left->data){
        x->left = rotate_left(x->left);
        return rotate_right(x);
    }

    return x;
}

void avl::preorder(node* x){
    if(x==NULL) return;
    cout<<x->data<<" ";
    preorder(x->left);
    preorder(x->right);
}

void avl::inorder(node* x){
    if(x==NULL) return;
    inorder(x->left);
    cout<<x->data<<" ";
    inorder(x->right);
}


int main(){
    avl a;
    a.root = a.insert(a.root,10);
    a.root = a.insert(a.root,15);
    a.root = a.insert(a.root,20);

    cout<<"\nInorder: ";
    a.inorder(a.root);
    cout<<"\nPreorder: ";
    a.preorder(a.root);
}