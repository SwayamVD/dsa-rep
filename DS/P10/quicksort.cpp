#include<iostream>
using namespace std;

//first element as pivot
// int partition(int arr[],int s,int e){
//     int p = arr[s];
//     cout<<"Pivot(index): "<<arr[p]<<"("<<p<<")"<<endl;
//     int c=0;
//     for(int i=s+1;i<=e;i++){
//         if(arr[i]<p){
//             c++;
//         }
//     }
//     //correct pivot index
//     int pi = s+c;
//     swap(arr[pi],arr[s]);
//     cout<<"Correct Pivot(index): "<<arr[pi]<<"("<<pi<<")"<<endl;

//     int i=s,j=e;
//     while(i<pi && j>pi){
//         while(arr[i]<=arr[pi] ){
//             i++;
//         }
//         while(arr[j]>arr[pi]){
//             j--;
//         }
//         if(i<pi && j>pi){
//             swap(arr[i++],arr[j--]);
//         }
//     }
//     return pi;
// }

//last element as pivot
int partition(int arr[],int s,int e){
    int p = arr[e];
    cout<<"Pivot(index): "<<arr[p]<<"("<<p<<")"<<endl;
    int c=0;
    for (int i = s; i < e-1; i++) {
        if (arr[i] < p) {
            c++;
        }
    }
    int pi = s+c;
    swap(arr[pi],arr[e]);
    cout<<"Correct Pivot(index): "<<arr[pi]<<"("<<pi<<")"<<endl;

    int i=s,j=e;
    while(i<pi && j>pi){
        while(arr[i]<=arr[pi] ){
            i++;
        }
        while(arr[j]>arr[pi]){
            j--;
        }
        if(i<pi && j>pi){
            swap(arr[i++],arr[j--]);
        }
    }
    return pi;
}

void quicksrt(int arr[],int s,int e){
    if(s<e){
        int pi = partition(arr,s,e);
        quicksrt(arr,s,pi-1);
        quicksrt(arr,pi+1,e);
    }
}
int main(){
    int arr[] = {6,3,2,7,1,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    quicksrt(arr,0,n-1);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}