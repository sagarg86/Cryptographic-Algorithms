#include <iostream>
#include <string>
using namespace std;

string generateKey(string msg, string keyWord){
    int sizeKeyword = keyWord.size();
    int msgSize = msg.size(); 
    if(sizeKeyword > msgSize){
        return keyWord.substr(0, msgSize);
    }
    for(int i=sizeKeyword; i<msg.size(); i++){
        keyWord.push_back(keyWord[i%sizeKeyword]);
    }
    return keyWord;
}
string encryption(string msg, string key) {
    string output;
    for(int i=0; i<msg.size(); i++){
        char x = (msg[i] + key[i]) % 26; 
        if(msg[i] == ' ')
            x = ' ';
        else
            x = x + 'A';
        output.push_back(x);
    }
    return output;
}
string decryption(string encrypt, string key) {
    string output;
    int j=0;
    for (int i=0; i<encrypt.size(); i++) { 
        char x = (encrypt[i] - key[i] + 26) % 26;
        if(encrypt[i] == ' ')
            x = ' ';
        else
            x = x + 'A';
        output.push_back(x);
    }
    return output;
}

int main() {
        string keyWord;
        cout<<"\nEnter the key word: \n";
        cin>>keyWord;
        string msg;
        cout<<"\nEnter the Message: \n";
        cin.ignore();
        getline(cin,msg);
        string key = generateKey(msg, keyWord);
        string encrypt = encryption(msg, key);
        string decrypt = decryption(encrypt, key);
        cout<<"\nGenerated key:"<<key;
        cout<<"\nOriginal Message: "<<msg;
        cout<<"\nEncrypted Message: "<<encrypt;
        cout<<"\nDecrypted Message: "<<decrypt;
    return 0;
}