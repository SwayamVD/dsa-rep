// Remove WhiteSpace from a String
#include<iostream>
#include<string>
using namespace std;
int main(){
    string oldstr,newstr = "";
    cout<<"Enter String: ";
    getline(cin,oldstr);
    int len = oldstr.length();
    for(int i=0;i<len;i++){
        if(oldstr[i] != ' '){
            newstr += oldstr[i];
        }
    }
    cout<<newstr;
    return 0;
}