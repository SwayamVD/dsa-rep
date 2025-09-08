#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 20

class Stack 
{
    int S[MAX];
    int top;

public:
    Stack(){ 
        top = -1; 
    }

    void push(int x){
        if (top == MAX - 1){
            cout << "Stack is full\n";
        }
        else{
            S[++top] = x;
        }
    }

    int pop(){
        if (top == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return S[top--];
    }

    int getTop(){
        if (top == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return S[top];
    }

    bool isempty() { 
        return top == -1; 
    }

    void display(){
        if (isempty()){
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--){
            cout << S[i] << " ";
        }
        cout << endl;
    }
};

class CharStack 
{
    string S[MAX];
    int top;

public:
    CharStack() 
    { 
        top = -1; 
    }

    void push(string x) 
    {
        if(top == MAX - 1)
        {
            cout << "Char stack is full\n";
        }
        else S[++top] = x;
    }

    string pop() 
    {
        if(top == -1) 
        {
            return "";
        }
        return S[top--];
    }

    string getTop() 
    {
        if(top == -1) 
        {
            return "";
        }
        return S[top];
    }

    bool isempty() 
    { 
        return top == -1; 
    }
};

bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void expressionEvaluation(Stack &s1) 
{
    char postfix[20];
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int len = strlen(postfix);
    for (int i = 0; i < len; i++) 
    {
        char ch = postfix[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') 
        {
            int val;
            cout << "Enter value for " << ch << ": ";
            cin >> val;
            s1.push(val);
        } 
        else if (isOperator(ch)) 
        {
            int val2 = s1.pop();
            int val1 = s1.pop();
            switch (ch) 
            {
                case '+': s1.push(val1 + val2); break;
                case '-': s1.push(val1 - val2); break;
                case '*': s1.push(val1 * val2); break;
                case '/': s1.push(val1 / val2); break;
            }
        }
    }

    cout << "Result: " << s1.pop() << endl;
}

string infixToPrefix(string infix) // Infix -> (A+(B*C))  =  +A*BC  <- Prefix
{
    string revInfix = "";
    for (int i = infix.length() - 1; i >= 0; i--) {
        char ch = infix[i];
        if (ch == '(') revInfix += ')';
        else if (ch == ')') revInfix += '(';
        else revInfix += ch;
    }

    CharStack s;
    string result = "";

    for (int i = 0; i < revInfix.length(); i++) 
    {
        char ch = revInfix[i];
        if (isalnum(ch)) 
        {
            result += ch;
        } 
        else if (ch == '(') 
        {
            s.push("(");
        } 
        else if (ch == ')') 
        {
            while (!s.isempty() && s.getTop() != "(") 
            {
                result += s.pop();
            }
            s.pop(); // pop '('
        } 
        else 
        {
            while (!s.isempty() && isOperator(s.getTop()[0])) 
            {
                result += s.pop();
            }
            s.push(string(1, ch));
        }
    }

    while (!s.isempty()) 
    {
        result += s.pop();
    }

    string prefix = "";
    for (int i = result.length() - 1; i >= 0; i--) 
    {
        prefix += result[i];
    }

    return prefix;
}


string infixToPostfix(string infix) // Infix -> A+(B*C) = ABC*+
{
    CharStack s;
    string result = "";
    
    for (int i = 0; i < infix.length(); i++) 
    {
        char ch = infix[i];
        if (isalnum(ch)) result += ch;
        else if (ch == '(') s.push("(");
        else if (ch == ')') 
        {
            while (!s.isempty() && s.getTop() != "(") 
            {
                result += s.pop();
            }
            s.pop(); // pop '('
        } 
        else 
        {
            while (!s.isempty() && isOperator(s.getTop()[0])) 
            {
                result += s.pop();
            }
            s.push(string(1, ch));
        }
    }

    while (!s.isempty()) 
    {
        result += s.pop();
    }

    return result;
}


string prefixToPostfix(string prefix) // (Prefix) +A*BC  =  (Postfix) ABC*+  =  (Infix) A+(B*C)
{
    CharStack s;
    for (int i = prefix.length() - 1; i >= 0; i--) 
    {
        char ch = prefix[i];
        if (isOperator(ch)) 
        {
            string op1 = s.pop();
            string op2 = s.pop();
            s.push(op1 + op2 + ch);
        } 
        else 
        {
            s.push(string(1, ch));
        }
    }
    return s.getTop();
}

string prefixToInfix(string prefix) //  Prefix ->  +A*BC = (A+(B*C))  <-Infix
{
    CharStack s;
    for (int i = prefix.length() - 1; i >= 0; i--) 
    {
        char ch = prefix[i];
        if (isOperator(ch)) 
        {
            string op1 = s.pop();
            string op2 = s.pop();
            s.push("(" + op1 + ch + op2 + ")");
        } 
        else 
        {
            s.push(string(1, ch));
        }
    }
    return s.getTop();
}

string postfixToInfix(string postfix) //  Postfix->  ABC*+ = A+(B*C)  <-Infix
{
    CharStack s;
    for (int i = 0; i < postfix.length(); i++) 
    {
        char ch = postfix[i];
        if (isOperator(ch)) 
        {
            string op2 = s.pop();
            string op1 = s.pop();
            s.push("(" + op1 + ch + op2 + ")");
        } 
        else 
        {
            s.push(string(1, ch));
        }
    }
    return s.getTop();
}

string postfixToPrefix(string postfix) //   (Postfix) ABC*+  =  (Prefix) +A*BC  =   (Infix) A+(B*C)
{
    CharStack s;
    for (int i = 0; i < postfix.length(); i++) 
    {
        char ch = postfix[i];
        if (isOperator(ch)) 
        {
            string op2 = s.pop();
            string op1 = s.pop();
            s.push(ch + op1 + op2);
        } 
        else 
        {
            s.push(string(1, ch));
        }
    }
    return s.getTop();
}

int main() 
{
    Stack s1;
    int element, choice;
    string expr;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Get Top\n4. Evaluate Postfix\n";
        cout << "5. Infix to Prefix\n6. Infix to Postfix\n7. Prefix to Postfix\n8. Prefix to Infix\n";
        cout << "9. Postfix to Infix\n10. Postfix to Prefix\n11. Display Stack\n12. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter element to push: ";
                cin >> element;
                s1.push(element);
                break;
            case 2:
                cout << "Popped Element: " << s1.pop() << endl;
                break;
            case 3:
                cout << "Top Element: " << s1.getTop() << endl;
                break;
            case 4:
                expressionEvaluation(s1);
                break;
            case 5:
                cout << "Enter Infix: ";
                cin >> expr;
                cout << "Prefix: " << infixToPrefix(expr) << endl;
                break;
            case 6:
                cout << "Enter Infix: ";
                cin >> expr;
                cout << "Postfix: " << infixToPostfix(expr) << endl;
                break;     
            case 7:
                cout << "Enter Prefix: ";
                cin >> expr;
                cout << "Postfix: " << prefixToPostfix(expr) << endl;
                break;
            case 8:
                cout << "Enter Prefix: ";
                cin >> expr;
                cout << "Infix: " << prefixToInfix(expr) << endl;
                break;
            case 9:
                cout << "Enter Postfix: ";
                cin >> expr;
                cout << "Infix: " << postfixToInfix(expr) << endl;
                break;
            case 10:
                cout << "Enter Postfix: ";
                cin >> expr;
                cout << "Prefix: " << postfixToPrefix(expr) << endl;
                break;
            case 11:
                s1.display();
                break;
            case 12:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } 
    while (choice != 12);

    return 0;
}
