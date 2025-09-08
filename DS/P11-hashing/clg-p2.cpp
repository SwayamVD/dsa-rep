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
	void quadraticprob(int key);
	int search(int key);
	void deletekey(int key);
	void display();
};

int hashtable::hash(int key){
	return key % 10;
}

void hashtable::quadraticprob(int key){
	for(int i=0;i<size;i++){
		int index = (hash(key) + i*i) % size;
		if(ht[index]==0){
			ht[index]=key;
			break;
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
	h.quadraticprob(10);
	h.quadraticprob(24);
	h.quadraticprob(32);
	h.quadraticprob(42);
	h.display();
	cout<<"Element found at index: "<<h.search(10)<<endl;
	h.deletekey(24);
	cout<<"Element Deleted! at index 4 "<<endl;
	h.display();
}
