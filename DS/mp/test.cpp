#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "Swayam sdfsdgsdfsdfsdfsdfsfdsfsdg";
    long sd=2;
    for(int i=0;i<=s.length();i++){
        sd += (int)s[i];
    }
    cout<<sd*10;
}