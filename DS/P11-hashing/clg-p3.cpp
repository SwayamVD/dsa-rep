#include<iostream>
using namespace std;


#define size 10
class hashtable{
	int ht[size];
	public:
	hashtable(){
		for(int i=0;i<size;i++){
			ht[i] = 0;
		}
	}
	int hash(int key);
	void linearprob(int key);
	int search(int key);
	void deletekey(int key);
	void display();
};

int hashtable::hash(int key){
	return key % 10;
}

void hashtable::linearprob(int key){
	int temp,index;
	for(int i=0;i<size;i++){
		index = (hash(key) + i*i) % size;
		if(ht[index]==0){
			ht[index]=key;
			break;
		}
		else{
			temp = ht[index];
			ht[index] = key;
			for(int j = (index+1)%size; (i%size)!=index; i = ((i%size)+1)){
				if(ht[j]==0){
					ht[j] = temp;
					return;
				}
			}
		}
	}
}

int hashtable::search(int key){
	for(int i=0;i<size;i++){
		if(ht[i]==key){
			return i;
		}
	}
	return -1;
}

void hashtable::display(){
	for(int i=0;i<size;i++){
		cout<<"index ( "<<i<<" ) = "<<ht[i]<<endl;
	}
}

void hashtable::deletekey(int key){
	for(int i=0;i<size;i++){
		if(ht[i]==key){
			ht[i] = 0;
		}
	}
}



int main(){
	hashtable h;
	h.linearprob(11);
	h.linearprob(24);
	h.linearprob(32);
	h.linearprob(42);
	h.linearprob(39);
	h.linearprob(49);
	h.display();
	cout<<"Element found at index: "<<h.search(42)<<endl;
	h.deletekey(24);
	cout<<"Element Deleted! at index 4 "<<endl;
	h.display();
}
