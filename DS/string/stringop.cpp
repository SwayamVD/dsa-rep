#include<iostream>
#include<cstring>
using namespace std;

void freqcount(char s[100]){
    int cnt = 0;
    char ch;
    cout<<"Enter Charactor to count: ";
    cin>>ch;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==ch){
            cnt++;
        }
    }
    cout<<"Frequence of "<<ch<<" in String is "<<cnt<<endl;
}

void strextract(char s[100]){
    char newstr[100];
    newstr[0] = '\0';
    int str, len;
    cout<<"Enter Starting Position: ";
    cin>>str;
    cout<<"Enter Length of Substring: ";
    cin>>len;
    int k =0;
    for(int i=str;i<=len;i++){
        newstr[k] = s[i];
        k++;
    }
    newstr[k] = '\0';
    cout<<"Your Substring is : "<<newstr<<endl;
}

void removeoccur(char s[100]){
    char newstr[100];
    newstr[0] = '\0';
    char ch;
    cout<<"Enter Charactor to remove its Occurances: ";
    cin>>ch;
    int k = 0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] != ch){
            newstr[k] = s[i];
            k++;
        }
    }
    newstr[k] = '\0';
    cout<<"New String without Occurance of given charactor : "<<newstr<<endl;
}
#include <iostream>
#include <cstring>
using namespace std;

void inplacereplace(char s[100]) {
    char result[100] = "";
    char substr[100], repstr[100];
    int i = 0, k = 0;

    cin.ignore();  // flush leftover newline
    cout << "Enter the Substring for inreplacement: ";
    cin.getline(substr, 100);

    cout << "Enter the Replace string: ";
    cin.getline(repstr, 100);

    int lensubstr = strlen(substr);
    int lenrepstr = strlen(repstr);

    while (s[i] != '\0') {
        if (strncmp(&s[i], substr, lensubstr) == 0) {
            for (int j = 0; j < lenrepstr; j++) {
                result[k++] = repstr[j];  // fix: use result[k++] = ...
            }
            i += lensubstr;
        } else {
            result[k++] = s[i++];
        }
    }

    result[k] = '\0';  // fix: proper null-termination
    cout << "In Replace result is: " << result << endl;
}

void inplacestring(){
    string w,x,name;
    cout<<"Enter new string: ";
    cin>>name;
    cout<<"Enter Substring: ";
    cin>>w;
    cout<<"Enter Replacement String: ";
    cin>>x;
    size_t found = name.find(w);
    if(found!=string::npos){
        name.replace(found,w.length(),x);
        cout<<name;
    }
    else{
        cout<<"Substring not found";
    }
}

int main(){
    inplacestring();
    char str[100];
    str[0] = '\0';
    cout<<"Enter String: ";
    cin.getline(str,100);
    inplacereplace(str);
    freqcount(str);
    strextract(str);
    removeoccur(str);
}