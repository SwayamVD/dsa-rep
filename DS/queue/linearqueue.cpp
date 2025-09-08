#include<iostream>
using namespace std;

#define SIZE 10

class queue{
    public:
    string arr[SIZE]; 
    int front,rear; 
    queue(){
        front = -1;
        rear = -1;
    }

    void enqueue(string d){
        if(rear == SIZE - 1){ 
            cout<<"Queue Overflow"<<endl;
            return;
        }

        if(front == -1){ front = 0; }

        rear++;
        arr[rear] = d;
        cout<<"Order Registered"<<endl;
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout<<"Queue Empty"<<endl;
            return;
        }
        cout<<"Order Deleted: "<<arr[front]<<endl;
        front++;
    }

    void display(){
        if(front == -1 || front > rear){
            cout<<"Queue Empty";
            return;
        }
        cout<<"All Orders: "<<endl;
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    queue q;
    q.enqueue("Panner Pizza");
    q.enqueue("Nonveg Pizza");
    q.enqueue("Soyabeen Pizza");
    q.display();
    q.dequeue();
    q.display();
}