#include<iostream>
using namespace std;

#define MAX 5

class Stacks{
    int top;
    int s[MAX];

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

int Stacks::size(){
    return top+1;
}
int main(){
    Stacks s;
    s.push(10);
    s.push(20);
    s.display();
    s.pop();
    s.display();
    cout<<"Peek: "<<s.peek()<<endl;
    cout<<"Total elements in stack: "<<s.size()<<endl;
}