#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(double a, double b)
{
    return a > b;
}

#define PKG_N 3
#define TRUCK_CAP 50

class Relieforg
{
public:
    // weight,value,p/w
    double knapsack[PKG_N][3];
    void getinfo();
    void greedy();
};

void Relieforg::getinfo()
{
    for (int i = 0; i < PKG_N; i++)
    {
        cout << "Enter " << (i + 1) << "'s Weight, Value: ";
        cin >> knapsack[i][0] >> knapsack[i][1];
        knapsack[i][2] = knapsack[i][1] / knapsack[i][0];
    }
    cout << "Data Entered Successfully\n";
    for (int i = 0; i < PKG_N; i++)
    {
        for (int j = i + 1; j < PKG_N; j++)
        {
            if (knapsack[i][2] < knapsack[j][2])
            {
                for (int k = 0; k < 3; k++)
                {
                    double temp = knapsack[i][k];
                    knapsack[i][k] = knapsack[j][k];
                    knapsack[j][k] = temp;
                }
            }
        }
    }
}

void Relieforg::greedy()
{
    int currentcap = TRUCK_CAP;
    double benefit = 0.0;
    for (int i = 0; i < PKG_N; i++)
    {
        if (knapsack[i][0] <= currentcap)
        {
            benefit += knapsack[i][1];
            currentcap -= knapsack[i][0];
            cout << "Selected Package (" << knapsack[i][0] << "," << knapsack[i][1] << ")\n";
        }
        else
        {
            double frac = currentcap * knapsack[i][2];
            benefit += frac;
            currentcap = 0;
            cout << "Selected Package (" << knapsack[i][0] << "," << knapsack[i][1] << ") Fractical value: " << frac << "\n";
        }
        cout << "currentcap: " << currentcap << endl;
    }
    cout << "Total Benefits obtained: " << benefit << endl;
    cout << "Total Truck Weight used: " << (TRUCK_CAP - currentcap) << endl;
}

int main()
{
    Relieforg r;
    r.getinfo();
    r.greedy();
}