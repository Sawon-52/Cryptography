#include<bits/stdc++.h>
using namespace std;

//Function declaration 
// Vigenere Cipher decryption
string Vigenere_Cipher_decryption(string message,string key);


int main(){
	string s;
	string key="patapon";
	cout<<"Enter Ciphertext: ";
	getline(cin,s);
	cout<<"Vigenere_Cipher_decryption: "<<Vigenere_Cipher_decryption(s,key)<<"\n";
	return 0;
}

// Vigenere Cipher decryption
string Vigenere_Cipher_decryption(string message,string key){
	int n = message.length(),m = key.length();
	int k=0,temp;
	string ency="";
	for(int i=0;i<n;++i,++k){
		if(message[i]==' '){
			ency+=' ';
			--k;
			continue;			
		}
		temp = (message[i] -'a') - (key[(k%m)] - 'a');
		ency += 'a' + (temp<0?(temp+26):temp) % 26;
	}
	return ency;
}

