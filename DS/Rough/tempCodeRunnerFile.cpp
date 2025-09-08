#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

class myset
{
public:
    int n;
    int s[20];

public:
    void readset();
    void display();
    myset intersection(myset);
    myset unionn(myset);
    myset diff(myset);
};

void myset::readset()
{
    cout << "Enter the Size of set:";
    cin >> n;
    cout << "Enter Set Element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
}
void myset::display()
{
    cout << "{";
    int temp = n - 1;

    for (int i = 0; i < n; i++)
    {
        cout << s[i];
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

myset myset::intersection(myset B)
{
    myset C;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < B.n; j++)
        {
            if (s[i] == B.s[j])
            {
                C.s[k] = s[i];
                k++;
                break;
            }
        }
    }

    C.n = k;
    C.display();
    return C;
}

myset myset::diff(myset B)
{
    myset E;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < B.n; j++)
        {
            if (s[i] == B.s[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            E.s[k] = s[i];
            k++;
        }
    }

    E.n = k;
    E.display();
    return E;
}

myset myset::unionn(myset B)
{
    myset D;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        D.s[k] = s[i];
        k++;
    }

    for (int i = 0; i < B.n; i++)
    {
        bool f = false;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == B.s[i])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            D.s[k] = B.s[i];
            k++;
        }
    }

    D.n = k;
    D.display();
    return D;
}

int main()
{
    myset A, B;

    A.readset();
    cout << "First set: ";
    A.display();

    B.readset();
    cout << "Second set: ";
    B.display();

    cout << "Intersection of A and B: ";
    A.intersection(B);

    cout << "Union of A and B: ";
    myset D = A.unionn(B);

    cout << "Difference of A and B: ";
    // myset E = A.unionn(B);
    A.diff(B);
}