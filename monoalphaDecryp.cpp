#include<bits/stdc++.h>
using namespace std;

// function declaration
string monoalphabeticDecryption(string cipher);


int main(){
    string s;
    cout<<"Enter Cypher text: ";
    getline(cin, s);
    string text = monoalphabeticDecryption(s);
    cout<<"After Decryption: "<<text<<"\n";
    return 0;

}

// monoalphabeticDecryption function
string monoalphabeticDecryption(string cipher){
    int n;
    n=cipher.length();

    int temp;
    string key = "abcdefghijklmnopqrstuvwxyz";
    string key2="zaybxcwdveuftgshriqjpkolnm";
    string decy="";
    for(int i=0; i<n; i++){
        for(int j=0; j<key2.length(); j++){
            if(cipher[i]==key2[j]){
                decy += key[j];
            }
        }
    }

    return decy;

}

