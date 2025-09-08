#include<iostream>
using namespace std;

void doshellsort(int a[20],int n){
    for(int gap=(n/2); gap>=1; gap = gap/2){
        for(int j = gap; j<n; j++){
            for(int i=j-gap; i>=0; i= i-gap){
                if(a[i+gap] > a[i]){
                    break;
                }
                else{
                    int temp = a[i+gap];
                    a[i+gap] = a[i];
                    a[i] = temp;
                }
            }
        }
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
    doshellsort(arr,n);
    display(arr,n);
}