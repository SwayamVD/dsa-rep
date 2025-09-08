#include<iostream>
#include<fstream>
using namespace std;

class SparseAdd{
    public: 
    int sp1[20][3], sp2[20][3], sp3[20][3];
    void read(int sp[20][3]);
    void add();
    void display(int sp[20][3]);
};

void SparseAdd::read(int sp[20][3]){
    // cout<<"Enter Number of Rows and Columns: ";
    // cin>>sp[0][0]>>sp[0][1];
    // cout<<"Enter Number of Non Zero Numbers: ";
    // cin>>sp[0][2];
    // for(int i=1;i<=sp[0][2];i++){
    //     cout<<"Enter Row-Column-Value: ";
    //     cin>>sp[i][0]>>sp[i][1]>>sp[i][2];
    // }

    fstream inputfile("input.txt");
    if(!inputfile){
        cout<<"Error Occured in File Handling!";
        return;
    }

    inputfile>>sp[0][0]>>sp[0][1]; 
    inputfile>>sp[0][2];
    for(int i=1;i<=sp[0][2];i++){
        inputfile>>sp[i][0]>>sp[i][1]>>sp[i][2];
    }


    for(int i=0;i<=sp[0][2];i++){
        cout<<sp[i][0]<<" "<<sp[i][1]<<" "<<sp[i][2]<<endl;
    }

}

void SparseAdd::add(){
    int i = 1, j = 1, k = 1;
    int m=sp1[0][2],n=sp2[0][2];
    sp3[0][0] = sp1[0][0];
    sp3[0][1] = sp1[0][1];
    while(i<=m && j<=n){
        if(sp1[i][0] == sp2[j][0]){
            if(sp1[i][1] == sp2[j][1]){
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sp1[i][2] + sp2[j][2];
                i++;
                j++;
                k++;
            }
            else if(sp1[i][1] < sp2[j][1]){
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sp1[i][2];
                i++;
                k++;
            }
            else{
                sp3[k][0] = sp2[j][0];
                sp3[k][1] = sp2[j][1];
                sp3[k][2] = sp2[j][2];
                j++;
                k++;
            }
        }
        else if(sp1[i][0] < sp2[j][0]){
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sp1[i][2];
                i++;
                k++;
        }
        else{
                sp3[k][0] = sp2[j][0];
                sp3[k][1] = sp2[j][1];
                sp3[k][2] = sp2[j][2];
                j++;
                k++;
        }
    }

    while(i<=m){
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sp1[i][2];
                i++;
                k++;
    }
    while(j<=n){
                sp3[k][0] = sp2[j][0];
                sp3[k][1] = sp2[j][1];
                sp3[k][2] = sp2[j][2];
                j++;
                k++;
    }

    sp3[0][2] = k-1;
}

void SparseAdd::display(int sp[20][3]){
    for(int i=0;i<=sp[0][2];i++){
        cout<<"| "<<sp[i][0]<<" , "<<sp[i][1]<<" , "<<sp[i][2]<<" |"<<endl;
    }
}

int main(){
    SparseAdd s;
    cout<<"Matrix A: "<<endl;
    s.read(s.sp1);
    cout<<"Continue? : ";
    int temp;
    cin>>temp;
    cout<<"Matrix B: "<<endl;
    s.read(s.sp2);
    s.add();
    cout<<"Addition Matrix C: "<<endl;
    s.display(s.sp3);
}