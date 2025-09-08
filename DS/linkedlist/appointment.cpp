#include<iostream>
using namespace std;

struct Node{
    int stime;
    int etime;
    bool isbooked;
    Node* next;
};

class Appointment{
    public:
    Node* head;
    Appointment(){
        head = nullptr;
    }

    void createslots(){
        int start = 9;
        for(int i=0;i<9;i++){
            Node* newnode = new Node();
            newnode->stime = start;
            newnode->etime = start+1;
            newnode->isbooked = false;
            newnode->next = NULL;

            if(!head){
                head = newnode;
            }
            else{
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            start++;
        }
        cout<<"Slots created from 9am to 18pm"<<endl;
    }

    void addslot(int st,int et){
        Node* temp = head;
        while(temp){
            if(temp->stime == st){
                if(temp->isbooked){
                    cout<<"Sorry, The TimeSlot is already Booked!"<<endl;   
                    return;
                }
                else{
                    temp->isbooked = true;
                    cout<<"TimeSlot from "<<temp->stime<<" To "<<temp->etime<<" is Booked"<<endl;
                    return;
                }
            }
            temp = temp->next;
        }
        cout<<"Invalid Time Slot!"<<endl;
    }

    void displayslots(){
        Node* temp = head;
        while(temp){
            cout<<"Time Slot: "<<temp->stime<<" To "<<temp->etime<<endl;
            cout<<"Is Booked: ";
            if(temp->isbooked){
                cout<<"BOOKED"<<endl;
            }
            else{
                cout<<"FREE"<<endl;
            }
            temp = temp->next;
        }
    }

    void displayfreeslots(){
        Node* temp = head;
        while(temp){
            if(temp->isbooked == false){
                cout<<"Time Slot: "<<temp->stime<<" To "<<temp->etime<<endl;
            }
            temp = temp->next;
        }
    }

    void cancelslot(int st,int et){
        Node* temp = head;
        while(temp){
            if(temp->stime == st && temp->etime == et){
                temp->isbooked = false;
                cout<<"TimeSlot from "<<temp->stime<<" to "<<temp->etime<<" is Canceled!";
                return;
            }
            temp = temp->next;
        }
        cout<<"Invalid Time Slot"<<endl;
    }
};

int main(){
    Appointment a;
    a.createslots();
    a.addslot(9,10);
    a.addslot(11,12);

    
    cout<<"\n\nDisplaying All TimeSlots"<<endl;
    a.displayslots();

    cout<<"\n\nDisplaying All FREE slots"<<endl;
    a.displayfreeslots();

    a.cancelslot(9,10);
    cout<<"\n\nDisplaying All TimeSlots"<<endl;
    a.displayslots();

}