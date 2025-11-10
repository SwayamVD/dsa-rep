/*
10. Each user in a social network is connected to others via "friend"
relationships. If user A and user B are friends, an undirected edge exists
between them. Write a menu-driven CPP program to represent this social
network using both adjacency matrix and adjacency list. The program should:
    1. Check if two users are directly connected
    2. Display all friends of a given user.
*/

#include <iostream>
#include <string>
using namespace std;

class social
{
public:
    int NF;
    string users[20];
    int friends[20][20] = {0};
    void getusers();
    void getfriends();
    void checkiffriends();
    void listfriends();
};

void social::getusers()
{
    cout << "Enter No. of Users: ";
    cin >> NF;
    for (int i = 0; i < NF; i++)
    {
        cout << "User " << i + 1 << ": ";
        cin >> users[i];
    }
}

void social::getfriends()
{
    int u1, u2;
    char ch, cr;
    do
    {
        cr = 'n';
        cout << "Enter User1 ID: ";
        cin >> u1;
        cout << "Enter User2 ID: ";
        cin >> u2;
        cout << "Confirm to Make Friend (y/n): ";
        cin >> cr;
        if (cr == 'y')
        {
            friends[u1][u2] = 1;
            friends[u2][u1] = 1;
        }
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void social::checkiffriends()
{
    int u1, u2;
    cout << "Enter Both user id: ";
    cin >> u1 >> u2;
    if (friends[u1][u2])
    {
        cout << "Yes they are Friends" << endl;
    }
    else
    {
        cout << "No they are not friends" << endl;
    }
}

int main()
{
    social s;
    s.getusers();
    s.getfriends();
    s.checkiffriends();
}