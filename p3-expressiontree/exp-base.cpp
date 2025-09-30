#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct node
{
    char ch;
    node *left;
    node *right;
    node(char c)
    {
        this->ch = c;
        this->left = this->right = nullptr;
    }
};

class exp
{
public:
    node *root;
    string s1;

    exp()
    {
        root = nullptr;
    }
    bool isoperator(char ch);
    void getstring();
    void buildtree();
    void preorderdisplay(node *root);
    void postorderdisplay(node *root);
    void inorderdisplay(node *root);
};

bool exp::isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void exp::getstring()
{
    cout << "\nEnter a postfix expression: ";
    cin >> s1;
    s1 += '#';
}

void exp::buildtree()
{
    stack<node *> stk;
    int cnt = 0;
    while (s1[cnt] != '#')
    {
        if (isoperator(s1[cnt]))
        {
            node *rl = stk.top();
            stk.pop();
            node *ll = stk.top();
            stk.pop();
            node *newl = new node(s1[cnt]);
            newl->right = rl;
            newl->left = ll;
            stk.push(newl);
        }
        else
        {
            node *newl = new node(s1[cnt]);
            stk.push(newl);
        }
        cnt++;
    }
    root = stk.top();
}

void exp::postorderdisplay(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderdisplay(root->left);
    postorderdisplay(root->right);
    cout << root->ch << " ";
}

void exp::preorderdisplay(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->ch << " ";
    preorderdisplay(root->left);
    preorderdisplay(root->right);
}

void exp::inorderdisplay(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderdisplay(root->left);
    cout << root->ch << " ";
    inorderdisplay(root->right);
}

int main()
{
    exp e;
    e.getstring();
    e.buildtree();
    cout << "\nExpression Tree (Postorder Traversal): ";
    e.postorderdisplay(e.root);
    cout << "\nExpression Tree (Postorder Traversal): ";
    e.preorderdisplay(e.root);
    cout << "\nExpression Tree (Inorder Traversal): ";
    e.inorderdisplay(e.root);
    cout << endl;
    return 0;
}

/*
if char = operand : create node and push to stack
if char = operator : create node and pop 1 , pop 2 then node.left = 2, node.right = 1, then push node to stack

once string is empty then root = stack.pop
*/