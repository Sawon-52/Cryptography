#include<bits/stdc++.h>
using namespace std;

// function declaration
string monoalphabeticEncryption(string text);


int main(){
    string s;
    cout<<"Enter Plain text: ";
    getline(cin, s);
    string cipher = monoalphabeticEncryption(s);
    cout<<"After Encryption: "<<cipher<<"\n";
    return 0;

}

// monoalphabeticEncryption function
string monoalphabeticEncryption(string text){
    int n;
    n=text.length();

    int temp;
    string key = "zaybxcwdveuftgshriqjpkolnm";
    string ency="";
    for(int i=0; i<n; i++){
        temp = text[i]-'a';
        ency += key[temp];
    }

    return ency;

}

