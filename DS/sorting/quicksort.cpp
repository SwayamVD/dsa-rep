#include<iostream>
using namespace std;

int partition(int a[20],int lb,int ub){
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(a[start] <= pivot){
            start++;
        }
        while(a[end]> pivot){
            end--;
        }
        if(start < end){
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}

void quicksrt(int a[],int lb,int ub){
    if(lb < ub){
        int pi = partition(a,lb,ub);
        quicksrt(a,lb,pi-1);
        quicksrt(a,pi+1,ub);
    }
}

void display(int a[20],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int arr[6] = {23,2,64,7,24,81};
    int n = 6;
    quicksrt(arr,0,n-1);
    display(arr,n);
}