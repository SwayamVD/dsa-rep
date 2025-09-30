#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//node structure for dictionary
struct node{
    char keyword[20];
    char meaning[30];
    int ht;
    node* left;
    node* right;
    node(char key[20],char mean[30]){
        strcpy(this->keyword,key);
        strcpy(this->meaning,mean);
        this->ht = 1;
        this->left = this->right = nullptr;
    }
};

//main class;
class avl{
    public:
    node* root;
    avl(){
        root = nullptr;
    }
    int height(node* x);
    int balfac(node* x);
    node* rotate_right(node* x);
    node* rotate_left(node* x);
    node* rotate_leftright(node* x);
    node* rotate_rightleft(node* x);
    node* insert(node* x,char key[20],char mean[30]);
    void postorder(node* x);
    void inorder(node* x);
};

void avl::inorder(node* x){
    if(x==NULL) return;
    inorder(x->left);
    cout<<x->keyword<<" ";
    inorder(x->right);
}

void avl::postorder(node* x){
    if(x==NULL){
        return;
    }
    postorder(x->left);
    postorder(x->right);
    cout<<x->keyword<<" ";
}



node* avl::rotate_rightleft(node* x){
    x->right = rotate_right(x->right);
    return rotate_left(x);
}

node* avl::rotate_leftright(node* x){
    x->left = rotate_left(x->left);
    return rotate_right(x);
}


node* avl::insert(node* x,char key[20],char mean[30]){
    if(x==NULL){
        return new node(key,mean);
    }
    if(strcmp(key,x->keyword) < 0){
        x->left = insert(x->left,key,mean);
        if(balfac(x) == 2){
            if(strcmp(key,x->left->keyword) < 0){
                x = rotate_right(x);
            }
            else{
                x = rotate_leftright(x);
            }
        }
    }
    else if(strcmp(key,x->keyword)>0){
        x->right = insert(x->right,key,mean);
        if(balfac(x) == -2){
            if(strcmp(key,x->right->keyword) > 0){
                x = rotate_left(x);
            }
            else{
                x = rotate_rightleft(x);
            }
        }
    }
    else{
        cout<<"\nDuplicate Key is not allowed :0";
    }

    x->ht = height(x);
    return x;
}

int avl::height(node* x){
    if(x==NULL) return 0;
    int lh = height(x->left);
    int rh = height(x->right);
    return 1 + max(lh,rh);
}

int avl::balfac(node* x){
    return height(x->left) - height(x->right);
}

node* avl::rotate_right(node* x){
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* avl::rotate_left(node* x){
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

int main(){
    avl a;
    a.root = a.insert(a.root,"lda","dsf");
    a.root = a.insert(a.root,"sta","dsf");
    a.root = a.insert(a.root,"mov","dsf");
    // a.root = a.insert(a.root,"add","dsf");

    cout<<"\nInorder: ";
    a.inorder(a.root);
    cout<<"\nPostorder: ";
    a.postorder(a.root);


}