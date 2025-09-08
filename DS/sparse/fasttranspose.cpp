#include<iostream>
#include<fstream>
using namespace std;

class SparseMatrix{
    public:
    int sp1[20][3],sp2[20][3];
    void display(int sp[20][3]);
    void transpose();
    void read(int sp[20][3]);
};

void SparseMatrix::display(int sp[20][3]){
    for(int i=0;i<=sp[0][2];i++){
        cout<<sp[i][0]<<" "<<sp[i][1]<<" "<<sp[i][2]<<endl;
    }
}

void SparseMatrix::read(int sp[20][3]){
    cout<<"Enter Number of Rows and Columns: ";
    cin>>sp[0][0]>>sp[0][1];
    cout<<"Enter Number of Non Zero Numbers: ";
    cin>>sp[0][2];
    for(int i=1;i<=sp[0][2];i++){
        cout<<"Enter Row-Column-Value: ";
        cin>>sp[i][0]>>sp[i][1]>>sp[i][2];
    }
}

void SparseMatrix::transpose(){
    int row = sp1[0][0];
    int col = sp1[0][1];
    int M = sp1[0][2];
    sp2[0][0] = col;
    sp2[0][1] = row;
    sp2[0][2] = M;

    if(M==0){ return; }

    int freq[col];
    for(int i=0; i< col;i++){
        freq[i] = 0;
    }

    int temp;
    for(int i=1;i<=M;i++){
        temp = sp1[i][1];
        freq[temp] = freq[temp] + 1;
    }

    int rowstartpos[col];
    rowstartpos[0] = 1;
    for(int i=1;i<col;i++){
        rowstartpos[i] = rowstartpos[i-1] + freq[i-1];
    }

    int k;
    for(int i=1;i<=M;i++){
        k = rowstartpos[sp1[i][1]];
        sp2[k][0] = sp1[i][1];
        sp2[k][1] = sp1[i][0];
        sp2[k][2] = sp1[i][2];
        rowstartpos[k] = rowstartpos[k] + 1;
    }
}

int main(){
    SparseMatrix s;
    s.read(s.sp1);
    s.transpose();
    s.display(s.sp2);
}