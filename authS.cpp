#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr(26, vector<char>(26));

string generateKey(string text, string key)
{
    int x = text.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == text.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

void make_arr()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26 - i; j++)
        {
            arr[i][j] = char(j + i + 'a');
            //cout<<arr[i][j]<<" ";
        }
        int ch = 0;
        for (int j = 26 - i; j < 26; j++)
        {
            arr[i][j] = char('a' + ch);
            //cout<<arr[i][j]<<" ";
            ch++;
        }
        //cout<<endl;
    }
}

//function for encrypt plaint_text.
string encrypt(string text, string key)
{
    string res = "";
    int n = text.size();
    int m = key.size();
    for (int i = 0; i < n; i++)
    {
        res += arr[text[i] - 'a'][key[(i % m)] - 'a'];
    }
    return res;
}

//function for decrypt cypher_text.
string decrypt(string text, string key)
{
    string res = "";
    int n = text.size();
    int m = key.size();
    for (int i = 0; i < n; i++)
    {
        int idx = key[i % m] - 'a';
        for (int j = 0; j < 26; j++)
        {
            if (arr[j][idx] == text[i])
                res += char(j + 'a');
        }
    }
    return res;
}

int main()
{
    make_arr();
    string key, text;
    cout << "Enter key(for user1) : ";
    cin >> key;
    string key2;
    cout << "Enter key(for user2) : ";
    cin >> key2;
    cout << "Enter text : ";
    cin >> text;
    string generated_key = generateKey(text, key);
    // cout<<"\nGenerated key is : "<<generated_key;
    string encrypted1 = encrypt(text, key);
    string decrypted1 = decrypt(encrypted1, key2);
    
    if(text != decrypted1){
        cout<<"\nAuthentication invalid.";
        return 0;
    }
    string encrypted2 = encrypt(decrypted1, key2);
    string decrypted2 = decrypt(encrypted2, key);
    cout<<"\n";
    if(text == decrypted2){
        cout<<"\nAuthentication valid.";
    }
    else{
        cout<<"\nAuthentication invalid.";
    }
    return 0;
}