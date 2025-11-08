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
    string str;
    exp()
    {
        root = nullptr;
    }
    bool isoperator(char ch);
    void getstring();
    void buildtree();
    void inorderdisplay(node *x);
    void buildtreeprefix();
    int evaluate(node *root);
};

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

bool exp::isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void exp::getstring()
{
    cout << "Enter the Postfix expression string: ";
    cin >> str;
    str += '#';
}

void exp::buildtree()
{
    stack<node *> stk;
    int cnt = 0;
    while (str[cnt] != '#')
    {
        if (isoperator(str[cnt]))
        {
            node *rl = stk.top();
            stk.pop();
            node *ll = stk.top();
            stk.pop();
            node *nn = new node(str[cnt]);
            nn->left = ll;
            nn->right = rl;
            stk.push(nn);
        }
        else
        {
            node *nn = new node(str[cnt]);
            stk.push(nn);
        }
        cnt++;
    }
    root = stk.top();
}

void exp::buildtreeprefix()
{
    stack<node *> stk;
    int cnt = str.size() - 1;
    while (cnt >= 0)
    {
        if (isoperator(str[cnt]))
        {
            node *ll = stk.top();
            stk.pop();
            node *rl = stk.top();
            stk.pop();
            node *nn = new node(str[cnt]);
            nn->left = ll;
            nn->right = rl;
            stk.push(nn);
        }
        else
        {
            node *nn = new node(str[cnt]);
            stk.push(nn);
        }
        cnt--;
    }
    root = stk.top();
}

void exp::inorderdisplay(node *x)
{
    if (x == nullptr)
    {
        return;
    }
    inorderdisplay(x->left);
    cout << x->ch << " ";
    inorderdisplay(x->right);
}

int main()
{
    exp e;
    e.getstring();
    e.buildtree();
    e.inorderdisplay(e.root);
    cout << "\nAfter evaluation: " << e.evaluate(e.root);
    return 0;
}
