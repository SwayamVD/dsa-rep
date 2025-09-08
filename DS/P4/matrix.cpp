#include<iostream>
#include<string>
using namespace std;

class mat {
public:
    int sp1[50][3], sp2[50][3], sp3[50][3];
    void read(int sp[50][3]);
    void display(int sp[50][3]);
    void add();
};

void mat::read(int sp[50][3]) {
    cout << "Enter the size of the matrix (rows cols): ";
    cin >> sp[0][0] >> sp[0][1];
    cout << "Enter number of non-zero elements: ";
    cin >> sp[0][2];
    cout << "Enter non-zero elements (row column value): " << endl;
    for (int i = 1; i <= sp[0][2]; i++) {
        cin >> sp[i][0] >> sp[i][1] >> sp[i][2];
    }
}

void mat::display(int sp[50][3]) {
    cout << "Sparse Matrix Representation: " << endl;
    for (int i = 1; i <= sp[0][2]; i++) {
        cout<<"Row: "<< sp[i][0]<<"Column: "<< sp[i][1] <<"Value: "<< sp[i][2] << endl;
    }
}

void mat::add() {
    if (sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1]) {
        cout << "Matrix dimensions do not match!" << endl;
        return;
    }

    int k = 1;
    sp3[0][0] = sp1[0][0];
    sp3[0][1] = sp1[0][1];
    sp3[0][2] = 0;

    int i = 1, j = 1;
    while (i <= sp1[0][2] && j <= sp2[0][2]) {
        if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1]) {
            sp3[k][0] = sp1[i][0];
            sp3[k][1] = sp1[i][1];
            sp3[k][2] = sp1[i][2] + sp2[j][2];
            k++;
            i++;
            j++;
        } else if (sp1[i][0] < sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
            sp3[k][0] = sp1[i][0];
            sp3[k][1] = sp1[i][1];
            sp3[k][2] = sp1[i][2];
            k++;
            i++;
        } else {
            sp3[k][0] = sp2[j][0];
            sp3[k][1] = sp2[j][1];
            sp3[k][2] = sp2[j][2];
            k++;
            j++;
        }
    }

    while (i <= sp1[0][2]) {
        sp3[k][0] = sp1[i][0];
        sp3[k][1] = sp1[i][1];
        sp3[k][2] = sp1[i][2];
        k++;
        i++;
    }

    while (j <= sp2[0][2]) {
        sp3[k][0] = sp2[j][0];
        sp3[k][1] = sp2[j][1];
        sp3[k][2] = sp2[j][2];
        k++;
        j++;
    }
    sp3[0][2] = k - 1;
    cout<<"-----------------------Addition--------------------------";
    cout << "Resultant Sparse Matrix after addition: " << endl;
    display(sp3);
}
int main() {
    mat m;
    cout << "Reading first sparse matrix..." << endl;
    m.read(m.sp1);
    cout << "Reading second sparse matrix..." << endl;
    m.read(m.sp2);

    cout << "\nFirst Sparse Matrix:" << endl;
    m.display(m.sp1);
    cout << "\nSecond Sparse Matrix:" << endl;
    m.display(m.sp2);

    m.add();

    return 0;
}

