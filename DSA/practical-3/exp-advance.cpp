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
    void postfix2tree();
    void prefix2tree();
    void displaytree(node *root);
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

void exp::postfix2tree()
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

void exp::displaytree(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    displaytree(root->left);
    displaytree(root->right);
    cout << root->ch << " ";
}

int main()
{
    exp e;
    e.getstring();
    e.postfix2tree();
    cout << "\nExpression Tree (Postorder Traversal): ";
    e.displaytree(e.root);
    cout << endl;
    return 0;
}