#include<bits/stdc++.h>
using namespace std;

//Function declaration 
// Vigenere Cipher encryption
string Vigenere_Cipher_encryption(string text,string key);

int main(){
	string s;
	string key="patapon";
	cout<<"Enter Plaintext: ";
	getline(cin,s);
	string p = Vigenere_Cipher_encryption(s,key);
	cout<<"Vigenere_Cipher_encryption :"<<p<<"\n";
	return 0;
}


// Vigenere Cipher encryption
string Vigenere_Cipher_encryption(string text,string key){
	int n = text.length(),m = key.length();
	int k=0;
	string ency="";
	for(int i=0;i<n;++i,++k){
		if(text[i]==' '){
			ency+=' ';
			--k;
			continue;			
		}
        
		ency += 'a' + ( (text[i] -'a') + (key[(k%m)] - 'a') ) % 26;
	}
	return ency;
}

