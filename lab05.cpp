#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int generateRandomPrime(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
    } while (!isPrime(num));
    return num;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 1;
}

void generateKeys(int& public_key, int& private_key, int& n) {
    srand(time(0));

    int p = generateRandomPrime(100, 200);
    int q = generateRandomPrime(200, 300);

    n = p * q;
    int phi = (p - 1) * (q - 1);

    public_key = generateRandomPrime(2, phi - 1);
    private_key = modInverse(public_key, phi);
}

int encrypt(int msg, int public_key, int n) {
    return (int)pow(msg, public_key) % n;
}

int decrypt(int cipher_text, int private_key, int n) {
    return (int)pow(cipher_text, private_key) % n;
}

int main() {
    int public_key, private_key, n;

    generateKeys(public_key, private_key, n);

    int msg = 52;

    int cipher_text = encrypt(msg, public_key, n);

    cout << "Main Message: " << msg << endl;
    cout << "Encrypted Message: " << cipher_text << endl;

    int decryptedMsg = decrypt(cipher_text, private_key, n);

    cout << "Decrypted Message: " << decryptedMsg << endl;

    return 0;
}