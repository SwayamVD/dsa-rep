/*
6. A stock analyst records the daily stock prices of a company. They want to
quickly find the highest and lowest prices during a given period. Write a CPP
program using heap data structures to perform the following:
    1. Insert daily stock prices
    2. Display the maximum and minimum stock price.
    3. Delete the top most (maximum) price
    4. Display all prices in ascending or descending order
    5. Perform algorithmic analysis for insertion and deletion operation.
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N_STKS 5

class Stock
{
public:
    int heap[N_STKS];
    void insertarray();
    void getmaxmin();
    void deletetop(int n);
    void displayall();

    void buildheap(int n);
    void heapify(int n, int i);
    void heapsort(int n);
};

void Stock::insertarray()
{
    cout << "Enter Stock Prices " << endl;
    for (int i = 0; i < N_STKS; i++)
    {
        cout << "Stock " << i + 1 << " Price: ";
        cin >> heap[i];
    }
}

void Stock::heapsort(int n)
{
    buildheap(n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapify(i, 0);
    }
}

void Stock::buildheap(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }
}

void Stock::heapify(int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] < heap[max])
    {
        max = l;
    }

    if (r < n && heap[r] < heap[max])
    {
        max = r;
    }

    if (max != i)
    {
        swap(heap[i], heap[max]);
        heapify(n, max);
    }
}

void Stock::deletetop(int n)
{
    if (n <= 0)
    {
        cout << "Heap is Empty\n";
        return;
    }
    cout << "Top Maximum Element deleted: " << heap[0];
    heap[0] = heap[n - 1];
    n--;
    heapify(n, 0);
}

void Stock::getmaxmin()
{
    cout << "Maximum: " << heap[0] << endl;
    cout << "Minimum: " << heap[N_STKS - 1] << endl;
}

void Stock::displayall()
{
    cout << "\nStock Prices (Descending): ";
    for (int i = 0; i < N_STKS; i++)
        cout << heap[i] << " ";
    cout << endl;
    cout << "\nStock Prices (Ascending): ";
    for (int i = N_STKS - 1; i >= 0; i--)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    Stock s;
    int n = N_STKS;
    int ch;
    do
    {
        cout << "----MENU----" << endl;
        cout << "1. Insert Stock Prices" << endl;
        cout << "2. Perform HeapSort" << endl;
        cout << "3. Get Maximum and Minimum Stock Price" << endl;
        cout << "4. Delete Top" << endl;
        cout << "5. Display All" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.insertarray();
            break;
        case 2:
            s.heapsort(n);
            break;
        case 3:
            s.getmaxmin();
            break;
        case 4:
            s.deletetop(n);
            break;
        case 5:
            s.displayall();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 6);
}