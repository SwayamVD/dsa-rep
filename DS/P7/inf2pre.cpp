#include<iostream>
#include<string>
using namespace std;

#define MAX 20

class Stacks{
    int top;
    char s[MAX];

    public:
    Stacks(){
        top = -1;
    }
    void push(int e);
    void pop();
    int peek();
    int isEmpty();
    int isFull();
    int size();
    void display();
};
int Stacks::isEmpty(){
    if(s[top]==-1){
        return 1;
    }
    return 0;
}
int Stacks::isFull(){
    if(s[top]==MAX){
        return 1;
    }
    return 0;
}

void Stacks::push(int e){
    if(!isFull()){
        top++;
        s[top] = e;
    }
    else{
        cout<<"Stack is Full !"<<endl;
    }
}

void Stacks::pop(){
    if(!isEmpty()){
        s[top--];
    }
    else{
        cout<<"Stack is Empty !"<<endl;
    }
}

void Stacks::display(){
    cout<<"{";
    for(int i=0;i<=top;i++){
        cout<<s[i];
        if(i<top){
            cout<<",";
        }
    }
    cout<<"}";
}

int Stacks::peek(){
    return s[top];
}

int getPriority(char ch){
    if(ch == '#') return -1;
    if(ch == '(') return 0;
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
}

int operand(char ch){
    if(ch >= 'a' && ch <= 'z') return 1;
    return 0;
}
void convert(){
    Stacks s;
    s.push('#');
    string ansexp = "";
    char exp[30];
    cout<<"Enter your expression: ";
    cin>>exp;
    int i=0;
    while(exp[i] != '\0'){
        cout<<"its in the loop";
        char ch = exp[i+1];
        if(operand(ch)){
            ansexp += ch;
        }
        else{
            if(getPriority(s.peek())  >= getPriority(ch)){
                s.pop();
            }
            s.push(ch);
        }
        i++;
    }
    s.display();
}
int main(){
    convert();
}