/*
7. Write a menu driven CPP program to construct an expression tree for a
Boolean expression given in prefix for. Perform the following operations:
    1. Construct and display the tree.
    2. Traverse using inorder, preorder and post order (recursive and non
    recursive)3.
    3. Simplify the Boolean expression by applying logical laws.
    4. Swap left and rights up trees and display new traversal.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct node
{
    char ch;
    node *left;
    node *right;
    node(int data)
    {
        this->ch = data;
        this->left = this->right = nullptr;
    }
};

class exp
{
public:
    node *root;
    string str;
    exp()
    {
        root = nullptr;
    }
    bool isoperator(char c);
    void getstring();
    void buildprefixtree();
    void buildpostfixtree();
    int evaluate(node *root);
    void inorderrec(node *x);
    void inordernonrec();
    void preordernonrec();
    void postordernonrec();
};

void exp::preordernonrec()
{
    node *temp = root;
    stack<node *> stk;
    while (1)
    {
        while (temp != NULL)
        {
            cout << temp->ch << " ";
            stk.push(temp);
            temp = temp->left;
        }
        if (stk.empty())
            return;
        temp = stk.top();
        stk.pop();
        temp = temp->right;
    }
}

void exp::inordernonrec()
{
    node *temp = root;
    stack<node *> stk;
    while (1)
    {
        while (temp != NULL)
        {
            stk.push(temp);
            temp = temp->left;
        }
        if (stk.empty())
            return;
        temp = stk.top();
        stk.pop();
        cout << temp->ch << " ";
        temp = temp->right;
    }
}

void exp::postordernonrec()
{
    node *temp = root;
    stack<node *> stk1;
    stack<node *> stk2;
    stk1.push(temp);
    while (!stk1.empty())
    {
        temp = stk1.top();
        stk1.pop();
        stk2.push(temp);
        if (temp->left)
        {
            stk1.push(temp->left);
        }
        if (temp->right)
        {
            stk1.push(temp->right);
        }
    }
    while (!stk2.empty())
    {
        temp = stk2.top();
        stk2.pop();
        cout << temp->ch << " ";
    }
}

bool exp::isoperator(char c)
{
    return (c == '+' || c == '/' || c == '*' || c == '-');
}

void exp::getstring()
{
    cout << "Enter the expression string (prefix): ";
    cin >> str;
};

// only for prefix expression
void exp::buildprefixtree()
{
    stack<node *> stk;
    int cnt = str.size() - 1;
    while (cnt >= 0)
    {
        node *nn = new node(str[cnt]);
        if (isoperator(str[cnt]))
        {
            nn->left = stk.top();
            stk.pop();
            nn->right = stk.top();
            stk.pop();
        }
        stk.push(nn);
        cnt--;
    }
    root = stk.top();
}

// only for postfix expression (not asked but for practice)
void exp::buildpostfixtree()
{
    str += '#';
    stack<node *> stk;
    int cnt = 0;
    while (str[cnt] != '#')
    {
        node *nn = new node(str[cnt]);
        if (isoperator(str[cnt]))
        {
            nn->right = stk.top();
            stk.pop();
            nn->left = stk.top();
            stk.pop();
        }
        stk.push(nn);
        cnt--;
    }
    root = stk.top();
}

void exp::inorderrec(node *x)
{
    if (x == NULL)
        return;
    inorderrec(x->left);
    cout << x->ch << " ";
    inorderrec(x->right);
}

int exp::evaluate(node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->ch - '0';

    int lval = evaluate(root->left);
    int rval = evaluate(root->right);

    if (root->ch == '+')
        return lval + rval;
    if (root->ch == '-')
        return lval - rval;
    if (root->ch == '*')
        return lval * rval;
    if (root->ch == '/')
        return lval / rval;

    return 0;
}

int main()
{
    exp e;
    e.getstring();
    e.buildprefixtree();
    // e.inorderrec(e.root);
    cout << "\nPreorder Nonrec: ";
    e.preordernonrec();
    cout << "\nInorder Nonrec: ";
    e.inordernonrec();
    cout << "\nPostorder Nonrec: ";
    e.postordernonrec();
    cout << "\nAfter evaluation: " << e.evaluate(e.root) << endl;
}