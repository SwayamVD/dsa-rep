#include<iostream>
#include<stack>
using namespace std;

int checkpre(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}
bool isoperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
string infixtoprefix(string exp){
    stack<char> s;
    string ans;

    for(int i=0;i<exp.size();i++){
        if(isoperand(exp[i])){
            ans += exp[i];
        }
        else if(exp[i] == '('){
            s.push('(');
        }
        else if(exp[i] == ')'){
            while(s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop(); //for poping the ' ( '
        }
        else{
            //operator
            while(!s.empty() && checkpre(exp[i]) <= checkpre(s.top())){
                ans += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixtoprefix(exp);
    return 0;
}