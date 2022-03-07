#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void fill_map(map<char, string> &mp)
{
    mp.insert({'a', "00000"});
    mp.insert({'b', "00001"});
    mp.insert({'c', "00010"});
    mp.insert({'d', "00011"});
    mp.insert({'e', "00100"});
    mp.insert({'f', "00101"});
    mp.insert({'g', "00110"});
    mp.insert({'h', "00111"});
    mp.insert({'i', "01000"});
    mp.insert({'j', "01001"});
    mp.insert({'k', "01010"});
    mp.insert({'l', "01011"});
    mp.insert({'m', "01100"});
    mp.insert({'n', "01101"});
    mp.insert({'o', "01110"});
    mp.insert({'p', "01111"});
    mp.insert({'q', "10000"});
    mp.insert({'r', "10001"});
    mp.insert({'s', "10010"});
    mp.insert({'t', "10011"});
    mp.insert({'u', "10100"});
    mp.insert({'v', "10101"});
    mp.insert({'w', "10110"});
    mp.insert({'x', "10111"});
    mp.insert({'y', "11000"});
    mp.insert({'z', "11001"});
    mp.insert({' ', "11010"});
    mp.insert({'!', "11011"});
    mp.insert({'@', "11100"});
    mp.insert({'#', "11101"});
    mp.insert({'$', "11110"});
    mp.insert({'%', "11111"});
}

void extend_key(string &key, int n)
{
    for (int i = key.size(), j = 0; i < n; i++, j++)
    {
        if (j == key.size())
            j = 0;
        key.push_back(key[j]);
    }
}

string xor_operation(string a, string b)
{
    string res;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == '0' && b[i] == '0')
            res.push_back('0');
        else if (a[i] == '0' && b[i] == '1')
            res.push_back('1');
        else if (a[i] == '1' && b[i] == '0')
            res.push_back('1');
        else
            res.push_back('0');
    }
    return res;
}

string encrypt(map<char, string> mp, string plainText, string key)
{
    string cipher;
    for (int i = 0; i < plainText.size(); i++)
    {
        string res = xor_operation(mp[plainText[i]], mp[key[i]]);
        for (auto it : mp)
        {
            if (it.second == res)
                cipher += it.first;
        }
    }
    return cipher;
}
string decrypt(map<char, string> mp, string cipherText, string key)
{
    string original;
    for (int i = 0; i < cipherText.size(); i++)
    {
        string res = xor_operation(mp[cipherText[i]], mp[key[i]]);
        for (auto it : mp)
        {
            if (it.second == res)
                original += it.first;
        }
    }
    return original;
}

int main()
{
    
    string plaintext;
    cout << "Enter a message to encrypt: ";
    getline(cin, plaintext, '\n');

    string key;
    cout << "Enter key: ";
    cin >> key;

    map<char, string> mp;

    fill_map(mp);
    extend_key(key, plaintext.size());

    // cout << key << endl;

    // for (auto it : mp)
    //     cout << it.first << "  " << it.second << endl;

    string cipherText = encrypt(mp, plaintext, key);
    cout << "\nEncypted Text : " << cipherText << endl;

    string originalText = decrypt(mp, cipherText, key);
    cout << "\nOriginal Text : " << originalText << endl;

    return 0;
}