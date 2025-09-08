#include<iostream>
using namespace std;



struct Node{
    string reason;
    int time;
    Node* next;
    Node(string r,int t){
        this->reason = r;
        this->time = t;
        this->next = nullptr;
    }
};

class Appointment{
    public:
    int MAX_SLOTS = 9;
    Node* head;
    Appointment(){
        head = nullptr;
    }

    bool verifyTimeAvail(int t){
        Node* temp = head;
        if(MAX_SLOTS>0 && MAX_SLOTS<=9){
            while(temp){
                if(temp->time == t){
                    cout<<"Warning: Appointment with same time is present"<<endl;
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }
        else{
            cout<<"Warning: Maximum Appointment Slots Reached"<<endl;
            return false;
        }
    }
    void bookAppointment(string r,int t){
        if(verifyTimeAvail(t)){
            Node* n = new Node(r,t);
            if(!head){
                head = n;
                MAX_SLOTS--;
            }
            else{
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = n;
                MAX_SLOTS--;
            }
        }
    }
    void showAppointments(){
        if(head == nullptr){
            cout<<"No Appointments Now"<<endl;
        }
        else{
            Node* temp = head;
            while(temp){
                cout<<"Appointment Reason: "<<temp->reason;
                cout<<"   Time: "<<temp->time<<endl;
                temp = temp->next;
            }
        }
    }
    void cancelAppointments(int t){
        
        if(verifyTimeAvail(t)){
            cout<<"on line 75"<<endl;
            if(head->time == t){
                Node* t = head;
                head = t->next;
                delete t;
                return;
            }

            Node* temp = head;
            while(temp->next && temp->next->time != t){
                temp = temp->next;
            }
            if(temp->next == nullptr) return;
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout<<"Successfully Deleted the Appointment at"<<t<<endl;
        }
    }
};

int main(){
    Appointment a;
    a.bookAppointment("My first appointment",9);
    a.bookAppointment("My Second appointment",10);
    a.showAppointments();
    a.cancelAppointments(10);
    a.showAppointments();
}