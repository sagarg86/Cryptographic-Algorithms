#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "RC4 Stream Cipher";
    string message, key;
    cout << "\n\n Enter Plain Text: ";
    getline(cin, message);
    cout << "\n Enter Key: ";
    getline(cin, key);

    vector<int> S(256), K(256);

    // initialisation of state vector
    for (int i = 0; i < 256; i++)
        S[i] = i;

    for (int i = 0; i < 255; i++)
        K[i] = key[i % key.size()];

    // key scheduling algorithm
    int j = 0;
    for (int i = 0; i < 255; i++)
    {
        j = (j + S[i] + K[i]) % 256;
        swap(S[i], S[j]);
    }

    // pseudorandom generation algorithm
    string keystream;

    j = 0;
    for (int i = 0; i < message.size(); i++)
    {
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = S[i] + S[j] % 256;
        keystream[i] += char(S[t]);
    }

    // encryption
    string encryptedmessage;
    for (int i = 0; i < message.size(); i++)
        encryptedmessage += keystream[i] ^ message[i];
    cout << "\n Encrypted Text: " << encryptedmessage;

    // decryption
    string decryptedmessage;
    for (int i = 0; i < message.size(); i++)
        decryptedmessage += keystream[i] ^ encryptedmessage[i];
    cout << "\n Decrypted Text: " << decryptedmessage;
    
    return 0;
}