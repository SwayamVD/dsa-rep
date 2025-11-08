#include <iostream>
using namespace std;

#define N 3
#define CAP 50

class greedy
{
public:
    double knapsack[N][3];
    void getinfo();
    void sortbypw();
    void getoptimal();
    void displayknapsack();
};

void greedy::getoptimal()
{
    int currentcap = CAP;
    double result = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (knapsack[i][1] <= currentcap)
        {
            result += knapsack[i][0];
            currentcap -= knapsack[i][1];
            cout << "\nIncluded item (" << i + 1 << ") , Currect [Price][Remaining Capacity]: [" << result << "][" << currentcap << "]\n";
        }
        else
        {
            double frac = knapsack[i][2] * currentcap;
            result += frac;
            currentcap = 0;
            cout << "\nIncluded item (" << i + 1 << ") <fractional price: " << frac << "> , Currect [Price][Remaining Capacity]: [" << result << "][" << currentcap << "]\n";
            break;
        }
    }
}

void greedy::displayknapsack()
{
    cout << "Item\tPrice\tWeight\tP/W\t\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "\t" << knapsack[i][0] << "\t" << knapsack[i][1] << "\t" << knapsack[i][2] << "\t\n";
    }
}

void greedy::sortbypw()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
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
    cout << "\nSorted by P/Ws.\n";
    displayknapsack();
}

void greedy::getinfo()
{
    cout << "\nEnter Items information\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i + 1 << "'s Price, Weight: ";
        cin >> knapsack[i][0] >> knapsack[i][1];
        knapsack[i][2] = knapsack[i][0] / knapsack[i][1];
    }
    cout << "\nInfo entered successfully.\n";
    displayknapsack();
}

int main()
{
    greedy g;
    g.getinfo();
    g.sortbypw();
    g.getoptimal();
}