#include<iostream>
using namespace std;

void doinsertion(int a[20],int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i -1;

        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
    doinsertion(arr,n);
    display(arr,n);
}