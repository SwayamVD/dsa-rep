/*/
Algorithm for 
/*/
#include<iostream>
#include<stack>
using namespace std;

#define max 10

bool isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

string getInfix(string exp){
    stack<string> s;

    for(int i=0; exp[i]!='\0'; i++){
        
        if(isOperand(exp[i])){
            string op = string(1,exp[i]);
            s.push(op);
        }
        else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(exp[i] + op2 + op1);
        }
    }
    return s.top();
}
int main()
{
    string exp = "ABC/-AK/L-*";
    cout << getInfix(exp);
    return 0;
}