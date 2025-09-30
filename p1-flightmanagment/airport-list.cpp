#include<iostream>
using namespace std;

struct headnode{
    string city;
    headnode* next;
    adjnode* adj;
    headnode(string c){
        this->city = c;
        this->next = nullptr;
        this->adj = nullptr;
    }
};

struct adjnode{
    string cityname;
    int distance;
    float price;
    int fuel;
    adjnode* next;
    adjnode(string name,int d,float p,int f){
        this->cityname = name;
        this->distance = d;
        this->price = p;
        this->fuel = f;
        this->next  = nullptr;
    }
};


class airportlist{
    public:
    headnode* headroot;
    airportlist(){
        headroot = NULL;
    }
    void insertheadcity();
    void insertadjcity();
};
void airportlist::insertheadcity(){
    string n;
    cout<<"Enter (name): ";
    cin>>n;
    headnode* newnode = new headnode(n);
    if(!headroot){
        headroot = newnode;
    }
    else{
        headnode* temp = headroot;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void airportlist::insertadjcity(){
    string hc,ac;
    int d,f;
    float p;
    cout<<"Enter Head city: ";
    cin>>hc;
    headnode* temp = headroot;
    while(temp){
        if(temp->city == hc){
            int ch;
            do{
                cout<<"enter 0 to stop: ";
                cin>>ch;
                cout<<"Enter Adjacent City,Distance,Price,Fuel: ";
                cin>>ac>>d>>p>>f;
                adjnode* newadj = new adjnode(ac,d,p,f);
                if(!temp->adj){
                    temp->adj = newadj;
                }
                else{
                    adjnode* temp2 = temp->adj;
                    while(temp2->next != nullptr){
                        temp2 = temp2->next;
                    }
                    temp2 = newadj;
                }
            }while(ch!=0);
        }
    }
}

