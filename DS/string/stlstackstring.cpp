#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
    stack<char> s;
    string str,rev="";
    cout<<"Enter String: ";
    cin>>str;
    int i=0;
    while(str[i]!='\0'){
        s.push(str[i]);
        i++;
    }

    while(!s.empty()){
        rev += s.top();
        s.pop();
    }
    cout<<"Reversed String: "<<rev<<endl;

    if(rev == str){
        cout<<"Yes its Palimdrome String!!";
    }
    else{
        cout<<"No its not a palimdrome string!";
    }

}