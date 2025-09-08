#include<iostream>
using namespace std;
class SetOperations{
    int s[10];
    int n;
    public:
        void readset();
        void displayset();
        void intersection(SetOperations B);
        void unionofset();
        void difference();
};

void SetOperations::readset(){
    cout<<"Enter Length of Set: ";
    cin>>n;
    int i;
    for ( i = 0; i < n; i++)
    {
        cin>>s[i];
    }
}

void SetOperations::displayset(){
    int i;
    cout<<"{";
    for ( i = 0; i < n; i++)
    {
        cout<<s[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout << "}" << endl;
}

//intersection method
void SetOperations::intersection(SetOperations B){
    SetOperations T;
    int i,j,k=0;
    for(i=0;i<n;i++){
        for(j=0;j<B.n;j++){
            if(s[i]==B.s[j]){
                T.s[k]=s[i];
                k++;
                break;
            }
        }
    }
    T.n = k;
    cout<<"Intersection of Set A and Set B: ";
    T.displayset();
}




int main(){
    SetOperations A,B,C;
    A.readset();
    cout<<"Set A: ";
    A.displayset();
    B.readset();
    cout<<"Set B: ";
    B.displayset();
    A.intersection(B);
}