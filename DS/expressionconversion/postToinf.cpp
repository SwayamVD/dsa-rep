/*/
Algorithm for Postfix to Infix
1. Create an empty stack
2. traverse through prefix exp from left to right
3. if operand push to stack
4. if operator then pop 2 operands 
5. append them like this operand + operator + operand
6. continue till all the expression ends
7. display final converted string
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
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}
int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}