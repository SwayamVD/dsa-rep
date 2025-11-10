// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int ht;
    node(int d)
    {
        this->data = d;
        this->left = this->right = nullptr;
        this->ht = 1;
    }
};

class avl
{
public:
    node *root;
    avl()
    {
        root = nullptr;
    }
    int height(node *x)
    {
        if (x == NULL)
        {
            return 0;
        }
        int lh = height(x->left);
        int rh = height(x->right);
        return 1 + max(lh, rh);
    }

    int getbal(node *x)
    {
        return (height(x->left) - height(x->right));
    }

    node *rotateleft(node *x)
    {
        node *y = x->right;
        x->right = y->left;
        y->left = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    node *rotateright(node *x)
    {
        node *y = x->left;
        x->left = y->right;
        y->right = x;
        x->ht = height(x);
        y->ht = height(y);
        return y;
    }

    node *lr(node *x)
    {
        x->left = rotateleft(x->left);
        return rotateright(x);
    }

    node *rl(node *x)
    {
        x->right = rotateright(x->right);
        return rotateleft(x);
    }

    node *insert(node *x, int data)
    {
        if (x == NULL)
        {
            return new node(data);
        }
        if (data < x->data)
        {
            x->left = insert(x->left, data);
            if (getbal(x) == 2)
            {
                if (data < x->left->data)
                {
                    x = rotateright(x);
                }
                else
                {
                    x = lr(x);
                }
            }
        }
        else if (data > x->data)
        {
            x->right = insert(x->right, data);
            if (getbal(x) == -2)
            {
                if (data > x->right->data)
                {
                    x = rotateleft(x);
                }
                else
                {
                    x = rl(x);
                }
            }
        }
        else
        {
            cout << "\nDuplicate Data not allowed!";
        }

        x->ht = height(x);
        return x;
    }

    void inorder(node *x)
    {
        if (x == NULL)
            return;
        inorder(x->left);
        cout << x->data << " ";
        inorder(x->right);
    }

    void preorder(node *x)
    {
        if (x == NULL)
            return;
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
        }
};

int main()
{
    avl a;
    a.root = a.insert(a.root, 10);
    a.root = a.insert(a.root, 45);
    a.root = a.insert(a.root, 20);
    a.root = a.insert(a.root, 30);

    cout << "\nInorder: ";
    a.inorder(a.root);
    cout << "\nPreorder: ";
    a.preorder(a.root);
}