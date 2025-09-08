#include <iostream>
using namespace std;

#define size 10

class linearprob{
    int ht[size];
    public:
        linearprob(){
            for(int i=0;i<size;i++){
                ht[i]=0;
            }
        }
        int hash(int key);
        void inputlinearprob(int key);
        int search(int key);
        void display();
        void deletekey(int key);
};

int linearprob::hash(int key){
    return key % 10;
}

void linearprob::inputlinearprob(int key){
    if(search(key)!=-1){
        cout<<"Key already Exists!"<<endl;
    }
    int pos,i;
    pos = hash(key);
    if(ht[pos]==0 || ht[pos] == -1){
        ht[pos] = key;
        cout<<"Key("<<key<<") entered at index "<<pos<<endl;
        return;
    }
    else{
        for(i = (pos+1) % size; (i%size) != pos ; i = (i%size) + 1){
            if(ht[i]==0 || ht[i]==-1){
                ht[i]=key;
                cout<<"Key("<<key<<") entered at index "<<i<<endl;
                return;
            }
        }
    }
    cout<<"\n Hash table overflowed !\n";
}

int linearprob::search(int key){
    int pos,i; 
    pos = hash(key);

    if(ht[pos] == key){
        return pos;
    }

    for(i=(pos+1)%size;(i%size)!=pos;i=(i%size)+1){
        if(ht[i] == key){
            return i;
        }
        else if(ht[i] == 0){
            break;
        }
    }
    return -1;
}

void linearprob::deletekey(int key){
    int pos = search(key);
    if(pos == -1){
        cout<<"Key not found"<<endl;
        return;
    }
    cout<<"Key at index("<<pos<<") is Deleted \n";
    ht[pos] = -1;
}

void linearprob::display(){
    cout<<"\n ------------------------ \n";
    for(int i=0;i<size;i++){
        cout<<"Index("<<i<<") value["<<ht[i]<<"]"<<endl;
    }
    cout<<"\n ------------------------ \n";
}

int main(){
    linearprob l;
    l.inputlinearprob(12);
    l.inputlinearprob(27);
    l.inputlinearprob(53);
    l.inputlinearprob(23);
    l.display();
    l.deletekey(27);
    l.display();
    l.inputlinearprob(67);
    l.display();
    cout<<"Searched key found at index:"<<l.search(123)<<endl;
    
}