#include<iostream>
using namespace std;

class SetOp{
    public:
    int n;
    string S[10];
    void read(){
        cout<<"\nEnter Number of Students: ";
        cin>>n;
        cout<<"Enter Students Name-"<<endl;
        for(int i=0;i<n;i++){
            cout<<"Name of Student "<<i<<"  :";
            cin>>S[i];
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<S[i]<<" , ";
        }
    }

    SetOp intersection(SetOp A){
        SetOp B;
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<A.n;j++){
                if(S[i] == A.S[j]){
                    B.S[k] = S[i];
                    k++;
                    break;
                }
            }
        }

        B.n = k;
        return B;
    }

    SetOp difference(SetOp A){
        SetOp B;
        int k=0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<A.n;j++){
                if(S[i] == A.S[j]){
                    flag = true;
                    break;
                }
            }
            if(flag != true){
                B.S[k] = S[i];
                k++;
            }
        }
        B.n = k;
        return B;
    }


    SetOp unionset(SetOp A){
        SetOp B;
        int k=0;
        for(int i=0;i<n;i++){
            B.S[k] = S[i];
            k++;
        }

        for(int i=0;i<A.n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(S[j] == A.S[i]){
                    flag = true;
                    break;
                }
            }
            if(flag != true){
                B.S[k] = A.S[i];
                k++;
            }
        }
        B.n = k;
        return B;
    }
};

int main(){
    SetOp s1,s2,o1,o2,o3;
    s1.read();
    cout<<"\nSet 2: ";
    s1.display();
    s2.read();
    cout<<"\nSet 2: ";
    s1.display();
    cout<<"\nIntersection Operation: ";
    o1 = s1.intersection(s2);
    o1.display();

    cout<<"\nDifference Operation: ";
    o2 = s1.difference(s2);
    o2.display();

    cout<<"\nUnion Operation: ";
    o3 = s1.unionset(s2);
    o3.display();
}