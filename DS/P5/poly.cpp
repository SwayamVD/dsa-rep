#include<iostream>
using namespace std;
class poly{
    public:
    int p[20][2];
    int n;
    void readpoly();
    void displaypoly();
    poly addpoly(poly p1,poly p2);
    void sortpoly();
};
// void poly::sortpoly(){
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(p[j][1]>p[i][1]){
//                 int t1 = p[j][0];
//                 p[j][0] = p[i][0];
//                 p[i][0] = t1;

//                 int t2 = p[j][1];
//                 p[j][1] = p[i][j];
//                 p[i][1] = t2;
//             }
//         }
//     }
// }
void poly::readpoly(){
    cout<<"Enter number of Terms in Polynomial: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Term ("<<i<<"): "<<endl;
        cout<<"Enter Coefficient: ";
        cin>>p[i][0];
        cout<<"Enter Exponent: ";
        cin>>p[i][1];
    }
    cout<<"Polynomial Created Successfully"<<endl;
}
void poly::displaypoly(){
    for(int i=0;i<n;i++){
        cout<<p[i][0];
        if(p[i][1]!=0){
            cout<<"X^"<<p[i][1]<<" ";
        }
        if(i!=n-1){
            if(p[i][0]>=0){
                cout<<"+";
            }
        }
    }
    cout<<endl;
}
poly poly::addpoly(poly p1,poly p2){
    int i=0,j=0,k=0;
    while(i<p1.n && j<p2.n){
        if(p1.p[i][1]==p2.p[j][1]){
            p[k][0] = p1.p[i][0] + p2.p[j][0];
            p[k][1] = p1.p[i][1];
            i++;
            j++;
            k++;
        }
        else if(p1.p[i][1]<p2.p[j][1]){
            p[k][0] = p2.p[j][0];
            p[k][1] = p2.p[j][1];
            j++;
            k++;
        }
        else{
            p[k][0] = p1.p[i][0];
            p[k][1] = p1.p[i][1];
            i++;
            k++;
        }
    }
    // If any terms left in p1
    while (i < p1.n) {
        p[k][0] = p1.p[i][0];
        p[k][1] = p1.p[i][1];
        i++;
        k++;
    }

    // If any terms left in p2
    while (j < p2.n) {
        p[k][0] = p2.p[j][0];
        p[k][1] = p2.p[j][1];
        j++;
        k++;
    }
    n = k;
}
int main(){
    poly p1,p2,p3;
    p1.readpoly();
    // p1.sortpoly();
    p1.displaypoly();
    p2.readpoly();
    p2.displaypoly();
    p3.addpoly(p1,p2);
    cout<<"Addition of P1 and P2: ";
    p3.displaypoly();
}