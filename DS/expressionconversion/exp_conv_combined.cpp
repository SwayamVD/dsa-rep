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
string reversefunc(string str){
    int i=0,j=0;
    i = str.length() -1;
    while(j<i){
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j++;
        i--;
    }
    return str;
}

//Infix to Prefix
string inftopre(string exp){
    stack<char> s;
    string rev = reversefunc(exp); 
    int i = 0;
    string ans;
    while(i <= rev.length()-1){
        if(rev[i] == '('){
            rev[i] = ')';
        }
        else if(rev[i] == ')'){
            rev[i] = '(';
        }

        i++;
    }

    for(int i=0;i<rev.size();i++){
        if(isoperand(rev[i])){
            ans += rev[i];
        }
        else if (rev[i] == '('){
            s.push(rev[i]);
        }
        else if (rev[i] == ')'){
            while(s.top() != '(' ){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
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

    return reversefunc(ans);
}

//Infix to Postfix
string inftopost(string exp){
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

//Postfix to Infix
string posttoinf(string exp){
    stack<string> s;

    for(int i=0; exp[i]!='\0'; i++){
        
        if(isoperand(exp[i])){
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

//Prefix to Infix
string pretoinf(string exp){
    stack<string> s;
    int length = exp.size();
    for(int i=length-1;i>=0;i--){
        
        if(isoperand(exp[i])){
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

//Prefix to Postfix
string pretopost(string exp){
    stack<string> s;
    int length = exp.size();
    for(int i = length-1; i>=0;i--){
        
        if(isoperand(exp[i])){
            string op = string(1,exp[i]);
            s.push(op);
        }
        else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op1 + op2 + exp[i]);
        }
    }
    return s.top();
}

//Postfix to Prefix
string posttopre(string exp){
    stack<string> s;

    for(int i=0; exp[i]!='\0'; i++){
        
        if(isoperand(exp[i])){
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

int main(){
    string exp1 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix Expression: " << exp1 << endl << endl;

    cout << "Infix to Postfix: " << endl;
    cout << "Result: " << inftopost(exp1) << endl << endl;

    cout << "Infix to Prefix: " << endl;
    cout << "Result: " << inftopre(exp1) << endl << endl;

    string postfix = inftopost(exp1);
    cout << "Postfix to Infix: " << endl;
    cout << "Result: " << posttoinf(postfix) << endl << endl;

    string prefix = inftopre(exp1);
    cout << "Prefix to Infix: " << endl;
    cout << "Result: " << pretoinf(prefix) << endl << endl;

    cout << "Prefix to Postfix: " << endl;
    cout << "Result: " << pretopost(prefix) << endl << endl;

    cout << "Postfix to Prefix: " << endl;
    cout << "Result: " << posttopre(postfix) << endl << endl;

    return 0;
}
