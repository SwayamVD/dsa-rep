#include<iostream>
using namespace std;

struct Node{
    int cof;
    int exp;
    Node* next;
    Node(int cof1,int exp1){
        cof = cof1;
        exp = exp1;
        next = nullptr;
    }
};

class polyLink{
    
    public:
    Node* head;
    polyLink(){
        head = nullptr;
    }
    void read(int c,int e){
        Node* newNode = new Node(c,e);
        if(!head){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display(){
        if(head == nullptr){
            cout<<"Empty LinkedList";
        }
        else{
            Node* temp = head;
            while(temp){
                if(temp->cof >= 0){
                    if(temp != head){
                        cout<<"+ "<<temp->cof;
                    }
                    else{
                        cout<<temp->cof;
                    }
                }
                else{
                        cout<<temp->cof;
                }
                cout<<"X^"<<temp->exp<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    void addpoly(Node* p1,Node* p2){
        Node* t1 = p1;
        Node* t2 = p2;
        while(t1 && t2){
            if(t1->exp == t2->exp){
                int c = t1->cof + t2->cof;
                int e = t1->exp;
                read(c,e);
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->exp < t2->exp){
                read(t2->cof,t2->exp);
                t2 = t2->next;
            }
            else{
                read(t1->cof,t1->exp);
                t1 = t1->next;
            }
        }
        while(t1){
            read(t1->cof,t1->exp);
            t1 = t1->next;
        }
        while (t2)
        {
            read(t2->cof,t2->exp);
            t2 = t2->next;
        }
        
    }
    void sortpoly(){
        Node* t = head;
        Node* t2 = head->next;
        while(t){
            while(t2){
                if(t2->exp > t->exp){
                    int c = t2->cof;
                    t2->cof = t->cof;
                    t->cof = c;

                    int e = t2->exp;
                    t2->exp = t->exp;
                    t->exp = e;

                }
                t2 = t2->next;
            }
            t = t->next;
        }
    }
};
int main(){
    polyLink p,b,c;
    cout<<"Polynomial P: ";
    p.read(3,3);
    p.read(1,5);
    p.read(4,2);
    p.sortpoly();
    p.display();
    cout<<"Polynomial B: ";
    b.read(-5,3);
    b.read(1,4);
    b.read(4,2);
    b.sortpoly();
    b.display();
    cout<<"Addition of polynomials: ";
    c.addpoly(p.head,b.head);
    c.sortpoly();
    c.display();

}