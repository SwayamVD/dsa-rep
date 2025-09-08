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
    int length = exp.size();
    for(int i=length-1;i>=0;i--){
        
        if(isOperand(exp[i])){
            string op = string(1,exp[i]);
            s.push(op);
        }
        else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + exp[i] + op2 + ")");
        }
    }
    return s.top();
}
int main()
{
    string exp = "*-A/BC-/AKL";
    cout << getInfix(exp);
    return 0;
}