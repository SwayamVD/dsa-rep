#include<iostream>
using namespace std;

#define size 10

class quadraticprob{
    int ht[size];
    public:
    quadraticprob(){
        for(int i=0;i<size;i++){
            ht[i] = 0;
        }
    }
    int hash(int key);
    void insertquadraticprob(int key);
    void deletekey(int key);
    int search(int key);
    void display();
};

int quadraticprob::hash(int key){   
    return key % size;
}

void quadraticprob::insertquadraticprob(int key){
    if(search(key) != -1){
        cout<<"Key("<<key<<") already exists !";
        return;
    }
    int pos,i;
    for(i=0;i<size;i++){
        pos = (hash(key) + i*i) % size;
        if(ht[pos]==0 || ht[pos]==-1){
            ht[pos]=key;
            return;
        }
    }
    cout<<"Hash Table overflowed !";
}

int quadraticprob::search(int key){
    int pos,i;
        for(i=0;i<size;i++){
            pos = (hash(key) + i*i) % size;
            if(ht[pos]==key){
                return pos;
            }
            else if(ht[pos]==0){
                return -1;
            }
        }
    return -1;
}

void quadraticprob::deletekey(int key){
    int pos = search(key);
    if(pos == -1){
        cout<<"Key not found!";
        return;
    }
    ht[pos] = -1;
    cout<<"Key deleted at index("<<pos<<")";
    return;
}
void quadraticprob::display(){
    cout<<"\n ------------------------ \n";
    for(int i=0;i<size;i++){
        cout<<"Index("<<i<<") value["<<ht[i]<<"]"<<endl;
    }
    cout<<"\n ------------------------ \n";
}

int main(){
    quadraticprob q;
    q.insertquadraticprob(123);
    q.insertquadraticprob(165);
    q.insertquadraticprob(166);
    q.insertquadraticprob(53);
    q.insertquadraticprob(53);
    q.display();
    cout<<"Searched Key found at index: "<<q.search(123)<<endl;
    q.deletekey(123);
    q.insertquadraticprob(33);
    q.insertquadraticprob(23);
    q.insertquadraticprob(13);

    q.display();

}