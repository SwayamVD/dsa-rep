#include<iostream>
#include<string>
using namespace std;
class StringClass{
	string str;
	public:
	void read();
	void display();
	void checkoccur();
	void extractstr();
	void removechar();
	void palimdrome();
	void replaceStr();
};
void StringClass::read(){
	cout<<"Enter your String: ";
	getline(cin,str);
}
void StringClass::display(){
	cout<<"Your String: "<<str<<endl;
}
void StringClass::checkoccur(){
	char ch1;
	cout<<"-------Check Occurance of Charactor------"<<endl;
	cout<<"Enter charactor: ";
	cin>>ch1;
	int i,cnt=0,l=str.length();
	for(i=0;i<l;i++){
		if(str[i]==ch1){
			cnt++;
		}
	}
	cout<<"Total Occurance of ' "<<ch1<<" ' in "<<str<<" is: "<<cnt<<endl;
}
void StringClass::extractstr(){
	string temp="";
	int pos,len,i,l=str.length();
	cout<<"-------Extract new string------"<<endl;
	cout<<"Enter the Position: ";
	cin>>pos;
	cout<<"Enter Length: ";
	cin>>len;
	for(i=pos;i<len;i++){
		temp+=str[i];
	}
	cout<<"Extracted string: "<<temp<<endl;
}
void StringClass::removechar(){
	char ch;
	cout<<"-------Remove all Occurance of Charactor------"<<endl;
	cout<<"Enter charactor: ";
	cin>>ch;
	bool f = false;
	string temp="";
	int i,l=str.length();
	for(i=0;i<l;i++){
		if(str[i]!=ch){
			temp+=str[i];
			//str[i]=NULL;
		}
	}
	cout<<"Removed '"<<ch<<"' from "<<str<<" is: "<<temp<<endl;
}
void StringClass::palimdrome(){
	char ch;
	cout<<"-------Check Palimdrome String------"<<endl;
	string temp="";
	int i,l=str.length();
	for(i=l-1;i>=0;i--){
		temp+=str[i];
	}
	if(temp==str){
		cout<<str<<" is a Palimdrome string."<<endl;
	}
	else{
		cout<<"Its not palimdrome string"<<endl;
	}
}
void StringClass::replaceStr(){
	cout<<"-------Replace Substring------"<<endl;
	string substr,temp="";
	char ch;
	int i,l=str.length();
	cout<<"Enter your substring: ";
	cin>>substr;
	cout<<"Enter charactor to remove: ";
	cin>>ch;
	for(i=0;i<l;i++){
		if(str[i]==ch){
			temp+=substr;
		}
		else{
			temp+=str[i];
		}
	}
	cout<<temp<<endl;
	
}
int main(){
	StringClass s;
	s.read();
	s.display();
	int ch=0;
	while(true){
		cout<<"---------------------MENU----------------------";
		cout<<"1. Replace String\n2. Check If Palimdrome\n3. Remove Charactor from String\n4. Check Charactor Occurance\n5. Extract String\n6. Exit"<<endl;
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch){
				case 1:s.replaceStr();
						break;
				case 2:s.palimdrome();
						break;
				case 3:s.removechar();
						break;
				case 4:s.checkoccur();
						break;
				case 5:s.extractstr();
						break;
				case 6:return 0;
						break;
				default:cout<<"Enter Valid Choice!";
		}
	}

}
