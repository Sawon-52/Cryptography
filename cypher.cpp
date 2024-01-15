#include <iostream>
using namespace std;

string encryption(string input, int key);
string decryption(string input, int key);


int main(){
    string input;
    int key;
    cout << "Enter a sentence: ";
    getline(cin, input);
    cout << "Key: ";
    cin >> key;
    cout << "Plain Text: " << input << endl;
    cout << "Key: " << key << endl;
    
    
    // Encryption
    string cipher_text = encryption(input, key);
    cout << "\nCipher Text: " << cipher_text << endl;
    
    
    // Decryption
    string plain_text = decryption(cipher_text, key);
    cout << "\nPlain Text: " << plain_text << endl;
    
    
    return 0;
}


// Encryption Function
string encryption(string input, int key){
    string ans = "";
    for(int i=0; i<input.size(); i++){
        int val = input[i] - 97 + key;
        if(val > 25)
            val%=26;
        char c = val + 97;
        ans+=c;
    }
    return ans;
}

// Decryption Function
string decryption(string input, int key){
    string ans = "";
    for(int i=0; i<input.size(); i++){
        int val = input[i] - 97 - key;
        if(val < 0)
            val+=26;
        char c = val + 97;
        ans+=c;
    }
    return ans;   
}