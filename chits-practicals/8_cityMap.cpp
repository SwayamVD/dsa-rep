/*
8. A city map shows roads between different intersections. If a road exist
between intersection A and intersection B, there is an edge between them.
The edge represents the length of the road (in kilometers) or travel time (in
minutes). Write a CPP program to represent this road map using adjacentry
matrix and adjacent list. The program should:
    1. Check if a direct road exists between two intersections
    2. Display all connecting roads from a given intersection.
*/

#include <iostream>
#include <string>
using namespace std;

class intersection
{
public:
    int NI;
    string inter[20];
    int des[20][20] = {0};
    int time[20][20] = {0};
    void getintersections();
    void getroads();
    void displayinter();
    void displayall();
    void findroads();
    void findconnectingroads();
};

void intersection::getintersections()
{
    cout << "Enter no of Interesections: ";
    cin >> NI;
    for (int i = 0; i < NI; i++)
    {
        cout << "Intersection " << i + 1 << ": ";
        cin >> inter[i];
    }
}

void intersection::displayinter()
{
    cout << "\nIntersection" << endl;
    for (int i = 0; i < NI; i++)
    {
        cout << "ID: " << i << ", " << inter[i] << endl;
    }
}

void intersection::getroads()
{
    int i1, i2, t, d;
    char ch;
    do
    {
        cout << "Enter Source Id: ";
        cin >> i1;
        cout << "Enter Destination ID: ";
        cin >> i2;
        cout << "Enter Time: ";
        cin >> t;
        cout << "Enter Distance: ";
        cin >> d;
        time[i1][i2] = t;
        time[i2][i1] = t;
        des[i1][i2] = d;
        des[i2][i1] = d;
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void intersection::displayall()
{

    cout << "Source\t\tDestination\tTime\tFuel" << endl;

    for (int i = 0; i < NI; i++)
    {
        for (int j = 0; j < NI; j++)
        {
            if (time[i][j] != 0)
            {
                cout << inter[i] << "\t\t"
                     << inter[j] << "\t\t"
                     << time[i][j] << "\t"
                     << des[i][j] << endl;
            }
        }
    }
}

void intersection::findroads()
{
    int src, dis;
    cout << "Enter the Source Intersection ID: ";
    cin >> src;
    cout << "Enter the Destination Intersection ID: ";
    cin >> dis;

    // direct road
    if (time[src][dis] != 0)
    {
        cout << "Direct Route Exist: " << inter[src] << " to " << inter[dis] << " , time: " << time[src][dis] << " , fuel: " << des[src][dis] << endl;
        return;
    }

    // indirect road
    for (int mid = 0; mid < NI; mid++)
    {
        if (time[src][mid] != 0 && time[mid][dis] != 0)
        {
            cout << "InDirect Route Exist: " << inter[src] << " to " << inter[mid] << " to " << inter[dis] << " , time: " << time[src][mid] + time[mid][dis] << " , fuel: " << des[src][mid] + des[mid][dis] << endl;
            return;
        }
    }
}

int main()
{
    intersection f;
    f.getintersections();
    f.displayinter();
    f.getroads();
    f.displayall();
    f.findroads();
}