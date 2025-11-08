#include <stdio.h>
#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    int maxind = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[maxind])
    {
        maxind = l;
    }
    if (r < n && a[r] < a[maxind])
    {
        maxind = r;
    }
    if (maxind != i)
    {
        swap(a[i], a[maxind]);
        heapify(a, n, maxind);
    }
}

void build_Heap(int a[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n)
{
    build_Heap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {4, 10, 3, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << n << endl;
    heapSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
