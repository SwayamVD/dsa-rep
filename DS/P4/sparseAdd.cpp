#include<iostream>
#include<fstream>
using namespace std;
class sparseAdd{
    public:
    int sp1[20][3],sp2[20][3],sp3[20][3];
    void read(int sp[20][3]);
    void display(int sp[20][3]);
    void add();
};
void sparseAdd::read(int sp[20][3]){
    // cout<<"Enter Size of Matrix (rows,cols): ";
    // cin>>sp[0][0]>>sp[0][1];
    // cout<<"Enter Number of Non-Zero elements: ";
    // cin>>sp[0][2];
    
    // for(int i=1;i<=sp[0][2];i++){
    //     cout<<"Enter element no. "<<i<<" (row,col,element): ";
    //     cin>>sp[i][0]>>sp[i][1]>>sp[i][2];
    // }
    // cout<<"Matrix Entered Successfully"<<endl;
    
    ifstream inputFile("input.txt");  // Open file

    if (!inputFile) {  // Check if file opened successfully
        cerr << "Error opening file!" << endl;
        return;
    }

    inputFile >> sp[0][0] >> sp[0][1];  // Read matrix size
    inputFile >> sp[0][2];              // Read number of non-zero elements

    for (int i = 1; i <= sp[0][2]; i++) {
        inputFile >> sp[i][0] >> sp[i][1] >> sp[i][2];  // Read row, col, element
    }

    inputFile.close(); // Close file
    cout << "Matrix Read Successfully from input.txt" << endl;
}
void sparseAdd::display(int sp[20][3]){
    for(int i=0;i<=sp[0][2];i++){
        cout<<"| "<<sp[i][0]<<" , "<<sp[i][1]<<" , "<<sp[i][2]<<" |"<<endl;
    }
}

void sparseAdd::add(){
    if(sp1[0][0]!=sp2[0][0] || sp1[0][1]!=sp2[0][1])
    {
        cout<<"Both Matrix must have same size (rows X cols)!!";
        return;
    }
    
    int k=1;
    sp3[0][0] = sp1[0][0];
    sp3[0][1] = sp1[0][1];
    sp3[0][2] = 0;

    int i=1,j=1;
    while(i<=sp1[0][2] && j<=sp2[0][2]){
        if(sp1[i][0]==sp2[j][0] && sp1[i][1]==sp2[j][1]){
            sp3[k][0]=sp1[i][0];
            sp3[k][1]=sp1[i][1];
            sp3[k][2]=sp1[i][2]+sp2[j][2];
            k++;
            j++;
            i++;
        }
        else if(sp1[i][0]<sp2[j][0] || (sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1])){
            sp3[k][0]=sp1[i][0];
            sp3[k][1]=sp1[i][1];
            sp3[k][2]=sp1[i][2];
            k++;
            i++;
        }
        else{
            sp3[k][0]=sp1[j][0];
            sp3[k][1]=sp1[j][1];
            sp3[k][2]=sp1[j][2];
            k++;
            j++;
        }
    }
    while(i<=sp1[0][2]){
        sp3[k][0]=sp1[i][0];
        sp3[k][1]=sp1[i][1];
        sp3[k][2]=sp1[i][2];
        k++;
        i++;
    }
    while(j<=sp2[0][2]){
        sp3[k][0]=sp2[j][0];
        sp3[k][1]=sp2[j][1];
        sp3[k][2]=sp2[j][2];
        k++;
        j++;
    }
    sp3[0][2]=k-1;
    cout<<"Successfully Added Both Matrix"<<endl;
}
int main(){
    sparseAdd a;
    cout<<"------Enter 1st Matrix------"<<endl;
    a.read(a.sp1);
    cout<<"------Enter 2nd Matrix------"<<endl;
    a.read(a.sp2);
    cout<<"------1st Sparse Matrix------"<<endl;
    a.display(a.sp1);
    cout<<"------2nd Sparse Matrix------"<<endl;
    a.display(a.sp2);
    a.add();
    cout<<"------Addition of Sparse Matrix-------"<<endl;
    a.display(a.sp3);
}