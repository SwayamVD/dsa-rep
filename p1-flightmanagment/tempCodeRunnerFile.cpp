#include<iostream>
using namespace std;

struct node{
    string city;
    int dis,fuel;
    node* adj;
    node* next;
    node(string c){
        this->city = c;
        this->dis = this->fuel = 0;
        this->adj = nullptr;
    }
    node(string c,int d,int f){
        this->city = c;
        this->dis = d;
        this->fuel = f;
        this->next = nullptr;
    }
};

class airportlist2{
    public:
    node* root;
    void insert();
    void display();
};
void airportlist2::insert(){
    int ch,d,f;
    string city,hcity;
    do{
        cout<<"1. New city\n2. Add Adjacent City\n3. Exit\nEnter choice: ";
        cin>>ch;
        char choice;
        if(ch==1){
            do{
                cout<<"Enter city name: ";
                cin>>city;
                node* n = new node(city);
                if(!root){
                    root = n;
                }
                else{
                    node* temp = root;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp->next = n;
                }
                cout<<"Continue? (y,n): ";
                cin>>choice;
            }while(choice!='n');
        }
        else if(ch==2){
            do{
                if(!root){
                    cout<<"Enter Root Node Please!"<<endl;
                }
                cout<<"Enter head city: ";
                cin>>hcity;
                node* temp = root;
                while(temp->next != nullptr && temp->city != hcity){
                    temp = temp->next;
                }
                    if(temp->city == hcity){
                        cout<<"Enter City, Distance, Fuel: ";
                        cin>>city>>d>>f;
                        node* n = new node(city,d,f);
                        node* t = temp;
                        while(t->adj != nullptr){
                            t = t->adj;
                        }
                        t->adj = n;
                    }
                cout<<"Continue? (y,n): ";
                cin>>choice;
            }while(choice!='n');
        }
        else{
            cout<<"Invalid choice!"<<endl;
        }
    }while(ch!=3);
}

void airportlist2::display(){
    node* head = root;

    while (head != nullptr) {
        // Print head city
        cout << head->city;

        // Print its adjacency list
        node* adj = head->adj;
        while (adj != nullptr) {
            cout << " -> " << adj->city;
            adj = adj->adj;
        }

        cout << endl;

        // Print vertical bar if there's another head city
        if (head->next != nullptr) {
            cout << "     |" << endl;
        }

        head = head->next;
    }
}

int main(){
    airportlist2 a;
    a.insert();
    a.display();
}