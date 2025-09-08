#include<iostream>
using namespace std;
class SetNumOp{
    int s[10];
    int n;
    public:
        void readset();
        void displayset();
        void intersection(SetNumOp a);
        void unionset(SetNumOp a);
};
void SetNumOp::readset(){
    cout<<"Enter Length of Set: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
}
void SetNumOp::displayset(){
    cout<<"{";
    for(int i=0;i<n;i++){
        cout<<s[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}
void SetNumOp::intersection(SetNumOp B){
    SetNumOp T;
    int i,j,k=0;
    for(i=0;i<n;i++){
        for(j=0;j<B.n;j++){
            if(s[i]==B.s[j]){
                T.s[k]=s[i];
                k++;
            }
        }
    }
    T.n = k;
    cout<<"Intersection of Set A and Set B: ";
    T.displayset();
}
void SetNumOp::unionset(SetNumOp B){
    SetNumOp T;
    SetNumOp D;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        D.s[k] = s[i];
        k++;
    }

    for (int i = 0; i < B.n; i++)
    {
        bool f = false;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == B.s[i])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            D.s[k] = B.s[i];
            k++;
        }
    }
    T.n = k;
    T.displayset();
}
int main(){
    SetNumOp a,b;
    a.readset();
    cout<<"Set A: ";
    a.displayset();
    b.readset();
    cout<<"Set B: ";
    b.displayset();
    cout<<"-----------------------------------------------------"<<endl;
    a.intersection(b);
    a.unionset(b);
}