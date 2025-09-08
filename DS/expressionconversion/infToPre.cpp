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


string convertfunc(string exp){
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
int main(){
    string exp = "(a-b/c)*(a/k-l)";
    string ans = convertfunc(exp);
    cout<<ans;
}