#include<iostream>
#include<fstream>
using namespace std;

class SimpTrans{
    public:
    int sp1[20][3],sp2[20][3];
    void read(int sp[20][3]);
    void display(int sp[20][3]);
    void transpose();
};

void SimpTrans::display(int sp[20][3]){
    for(int i=0;i<=sp[0][2];i++){
        cout<<"| "<<sp[i][0]<<" , "<<sp[i][1]<<" , "<<sp[i][2]<<" |"<<endl;
    }
}

void SimpTrans::read(int sp[20][3]){
    fstream inputfile("input.txt");
    if (!inputfile) {
        cout << "Failed to open input.txt" << endl;
        return;
    }

    inputfile>>sp[0][0]>>sp[0][1];
    inputfile>>sp[0][2];
    for(int i=1;i<=sp[0][2];i++){
        inputfile>>sp[i][0]>>sp[i][1]>>sp[i][2];
    }
    display(sp);
}

void SimpTrans::transpose(){
    int i=1;
    sp2[0][0] = sp1[0][1];
    sp2[0][1] = sp1[0][0];
    if(sp1[0][2] == 0){
        return;
    }
    sp2[0][2] = sp1[0][2];
    for(int j=0;j<=sp1[0][1]-1;j++){
        for(int k=1;k<=sp1[0][2];k++){
            if(sp1[k][1]==j){
                sp2[i][0] = sp1[k][1];
                sp2[i][1] = sp1[k][0];
                sp2[i][2] = sp1[k][2];
                i++;
            }
        }
    }
}

int main(){
    SimpTrans s;
    cout<<"Entered Matrix: "<<endl;
    s.read(s.sp1);
    s.transpose();
    cout<<"After Transpose: "<<endl;
    s.display(s.sp2);
}