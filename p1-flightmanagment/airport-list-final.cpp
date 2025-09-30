#include<iostream>
using namespace std;

const int MAX_COUNT = 100;

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
    airportlist2(){
        root = NULL;
    }
    void insert();
    void display();
    void searchflight();
    bool isvesited(string city,string visited[],int visicount);
    node* findnode(string name);
    bool dfs(node* curr,string des,string visited[],int& visicount);
};

node* airportlist2::findnode(string name){
    node* temp = root;
    while(temp!=NULL){
        if(temp->city == name){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool airportlist2::isvesited(string city,string visited[],int visicount){
    for(int i=0;i<visicount;i++){
        if(visited[i] == city){
            return true;
        }
    }
    return false;
}

bool airportlist2::dfs(node* curr,string des,string visited[],int& visicount){
    if(curr == NULL) return false;
    if(curr->city == des) return true;
    visited[visicount++]=curr->city;
    node* adjnode = curr->adj;
    while(adjnode != NULL){
        if(!isvesited(adjnode->city,visited,visicount)){
            node* nextcity = findnode(adjnode->city);
            if(dfs(nextcity,des,visited,visicount)){
                return true;
            }
        }
        adjnode = adjnode->adj;
    }
    return false;
}

void airportlist2::searchflight(){
    string src,des;
    cout<<"Enter Source, Destination: ";
    cin>>src>>des;
    string visited[MAX_COUNT];
    int visicount = 0;
    node* temp = findnode(src);
    if(dfs(temp,des,visited,visicount)){
        cout<<"Path Exists!"<<endl;
    }
    else{
        cout<<"Path not Exists!";
    }
}


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
            cout << "  |  " << endl;
        }

        head = head->next;
    }
}

int main(){
    airportlist2 a;
    a.insert();
    a.display();
    a.searchflight();
}