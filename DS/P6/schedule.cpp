#include<iostream>
using namespace std;

struct Node{
    string appReason;
    int time;
    bool avail;
    Node* next;
    Node(string a, int t){
        if(!avail){
            this->appReason = a;
            this->time = t;
            this->avail = true;
            this->next = nullptr;
        }
    }
};
class Appointment{
    public:
    //9am to 6pm {9-10,10-11,11-12,12-1,1-2,2-3,3-4,4-5,5-6}
    int VISIT_SLOTS[9]={9,10,11,12,13,14,15,16,17};
    //check the availability of visit slot 0 -> free slot , 1 -> allocated
    bool AVAIL[9]={};
    Node* head;
    Appointment(){
        head = nullptr;
    }
    int checkAvail(int t){
        for(int i=0;i<9;i++){
            if(t == VISIT_SLOTS[i] && !AVAIL[i]){
                return i;
            }
        }
        return -1;
    }
    void displayFreeSlots(){
        cout<<"**********FREE TIME SLOTS*********"<<endl;
        for(int i=0;i<9;i++){
            if(!AVAIL[i]){
                cout<<"Slot No: "<<i+1<<" i.e. "<<i+9<<" to "<<i+10<<endl;
            }
        }
    }
    //function to cancel an appointment
    void cancelAppointment(int t){
            if(checkAvail(t) == -1){
                cout<<"Request to cancel this appointment at "<<t<<endl;
                if(head->time == t){
                    Node* temp = head;
                    head = temp->next;
                    delete temp;

                    cout<<"Successfully Deleted the Appointment"<<endl;
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
                cout<<"Successfully Deleted the Appointment"<<endl;
            }
    }
    void bookAppointment(string r,int t){
        int availInd = checkAvail(t);
        if(availInd != -1){
            Node* n = new Node(r,t);
            if(!head){
                head = n;
                AVAIL[availInd] = true;
            }
            else{
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next= n;
                AVAIL[availInd] = true;
            }
        }
        else{
            cout<<"Time Slot already Allocated"<<endl;
        }
    }
    void viewAppointment(){
        if(head == nullptr){
            cout<<"No Appointment Yet"<<endl;
        }
        else{
            Node* temp = head;
            while(temp){
                cout<<"Appointment Reason: "<<temp->appReason<<endl;
                cout<<"Time: "<<temp->time<<endl;
                cout<<"Availability: "<<temp->avail<<endl; 
                cout<<"NextPointer: "<<temp->next<<endl; 
                temp = temp->next;
            }
        }
    }
};

int main(){
    Appointment a;
    a.bookAppointment("First App",12);
    a.bookAppointment("Second App",9);
    a.bookAppointment("Third App",9);

    a.viewAppointment();

    cout<<"AVAIL arr: ";
    for(int i=0;i<9;i++){
        cout<<a.AVAIL[i]<<" ";
    }
    cout<<endl;
    // a.displayFreeSlots();
    a.cancelAppointment(12);


    // this cancel appoinment implementation is missing on thing that is to update the AVAIL arr after deleting the node
    cout<<"AVAIL arr: ";
    for(int i=0;i<9;i++){
        cout<<a.AVAIL[i]<<" ";
    }
}