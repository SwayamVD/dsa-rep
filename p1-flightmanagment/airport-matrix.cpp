#include <iostream>
#include <string>
using namespace std;

class flight
{
public:
    int NC;
    string cities[20];
    int time[20][20] = {0};
    int fuel[20][20] = {0};
    void getcities();
    void getflight();
    void findflight();
    void displaycities();
    void displayflights();
};

void flight::getcities()
{
    cout << "Enter No. of Cities: ";
    cin >> NC;
    for (int i = 0; i < NC; i++)
    {
        cout << "City " << i + 1 << ": ";
        cin >> cities[i];
    }
}

void flight::displaycities()
{
    cout << "\nCities" << endl;
    for (int i = 0; i < NC; i++)
    {
        cout << "ID: " << i << ", " << cities[i] << endl;
    }
}

void flight::getflight()
{
    int src, des, t, f;
    displaycities();
    char ch;
    do
    {
        cout << "Enter Source Id: ";
        cin >> src;
        cout << "Enter Destination Id: ";
        cin >> des;
        cout << "Enter Time Required: ";
        cin >> t;
        cout << "Enter Fuel Required: ";
        cin >> f;
        time[src][des] = t;
        time[des][src] = t;
        fuel[src][des] = f;
        fuel[des][src] = f;
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void flight::displayflights()
{
    cout << "Source\t\tDestination\tTime\tFuel" << endl;

    for (int i = 0; i < NC; i++)
    {
        for (int j = 0; j < NC; j++)
        {
            if (time[i][j] != 0)
            {
                cout << cities[i] << "\t\t"
                     << cities[j] << "\t\t"
                     << time[i][j] << "\t"
                     << fuel[i][j] << endl;
            }
        }
    }
}

void flight::findflight()
{
    int src, des;
    cout << "Enter Source City ID: ";
    cin >> src;
    cout << "Enter Destination City ID: ";
    cin >> des;

    // check if direct flight is there
    if (time[src][des] != 0)
    {
        cout << "Direct Flight Exist" << endl;
        cout << cities[src] << " to " << cities[des] << " , time: " << time[src][des] << " , fuel: " << fuel[src][des] << endl;
        return;
    }

    // for indirect search
    for (int mid = 0; mid < NC; mid++)
    {
        if (time[src][mid] != 0 && time[mid][des] != 0)
        {
            cout << "Indired Flight Exist" << endl;
            cout << cities[src] << " to " << cities[mid] << " to " << cities[des] << " , time: " << time[src][mid] + time[mid][des] << " , fuel: " << fuel[src][mid] + fuel[mid][des] << endl;
            return;
        }
    }

    cout << "No flight Exist" << endl;
    return;
}

int main()
{
    flight f;
    f.getcities();
    f.getflight();
    f.displaycities();
    f.displayflights();
    f.findflight();
}