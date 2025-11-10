/*
15. Write a menu driven CPP program to maintain an employee directory
using an AVL tree. Each node should contain employee ID (key) and employee
name (value). Perform the following operations:
    1. Insert a new employee record
    2. Search for an employee using their id
    3. Delete an employee record
    4. Display employee records and sorted order (ascending/descending)
    5. Calculate and display the height of the AVL tree
    6. Determine the maximum number of comparisons required for
    searching and employee.
*/

#include <iostream>
#include <string>
using namespace std;

struct node
{
    string name;
    int id;
    int ht;
    node *left;
    node *right;
    node(int id, string name)
    {
        this->id = id;
        this->name = name;
        this->ht = 1;
        this->left = this->right = nullptr;
    }
};

class emp
{
public:
    node *root;
    emp()
    {
        root = nullptr;
    }
    int height(node *x);
    int getbal(node *x);
    node *rotateright(node *x);
    node *rotateleft(node *x);
    node *rl(node *x);
    node *lr(node *x);
    node *insert(int id, string name, node *x);
    void menu();
    void inorder(node *x);
    void preorder(node *x);
    void postorder(node *x);
    void search(node *x, int id);
    void delelte(int id);
};

int emp::height(node *x)
{
    if (!x)
        return 0;
    int rc = height(x->right);
    int lc = height(x->left);
    return 1 + max(rc, lc);
}

int emp::getbal(node *x)
{
    return (height(x->left) - height(x->right));
}

node *emp::rotateright(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *emp::rotateleft(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *emp::rl(node *x)
{
    x->right = rotateright(x->right);
    return rotateleft(x);
}

node *emp::lr(node *x)
{
    x->left = rotateleft(x->left);
    return rotateright(x);
}

node *emp::insert(int id, string name, node *root)
{
    if (!root)
    {
        return new node(id, name);
    }
    if (id < root->id)
    {
        root->left = insert(id, name, root->left);
        if (getbal(root) == 2)
        {
            if (id < root->left->id)
            {
                root = rotateright(root);
            }
            else
            {
                root = lr(root);
            }
        }
    }
    else if (id > root->id)
    {
        root->right = insert(id, name, root->right);
        if (getbal(root) == -2)
        {
            if (id > root->right->id)
            {
                root = rotateleft(root);
            }
            else
            {
                root = rl(root);
            }
        }
    }
    else
    {
        cout << "Duplicate data not allowed" << endl;
    }
    root->ht = height(root);
    return root;
}

void emp::search(node *x, int id)
{
    if (!x)
    {
        cout << "Employee with ID: " << id << "Not found." << endl;
        return;
    }
    if (id < x->id)
    {
        search(x->left, id);
    }
    else if (id > x->id)
    {
        search(x->right, id);
    }
    else
    {
        cout << "Employee Found!!" << endl;
    }
}

void emp::delelte(node)