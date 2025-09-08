#include<iostream>
using namespace std;

struct poly{
    int coff;
    int expo;
};

void display(poly p[10],int n){
    for (int i = 0; i < n; i++) {
        cout << p[i].coff << "x^" << p[i].expo;
        if (i < n - 1) {
            cout << " + ";
        }
    }
    cout<<endl;
}

void add(poly p1[10],poly p2[10],int n1,int n2){
    poly r[10];
    int k=0,i=0,j=0;
    while(i<n1 && j<n2){
            if(p1[i].expo == p2[j].expo){
                r[k].coff = p1[i].coff + p2[j].coff;
                r[k].expo = p1[i].expo;
                k++;
                i++;
                j++;
            }
            else if(p1[i].expo > p2[j].expo){
                r[k] = p1[i];
                k++;
                i++;
            }
            else{
                r[k] = p2[j];
                k++;
                j++;
            }
    }
    while(i<n1){
                r[k] = p1[i];
                k++;
                i++;
    }
    while(j<n2){
                r[k] = p2[j];
                k++;
                j++;
    }


    display(r,k);
}

int main(){
    poly p1[10],p2[10];
    int n1,n2;

    cout<<"Enter Number of terms in 1st Poly: ";
    cin>>n1;
    for(int i=0;i<n1;i++){
        cout<<"Enter Coff: ";
        cin>>p1[i].coff;
        cout<<"Enter Expo: ";
        cin>>p1[i].expo;
    }

    cout<<"Enter Number of terms in 2nd Poly: ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        cout<<"Enter Coff: ";
        cin>>p2[i].coff;
        cout<<"Enter Expo: ";
        cin>>p2[i].expo;
    }

    display(p1,n1);
    display(p2,n2);

    add(p1,p2,n1,n2);
}