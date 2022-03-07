
#include<bits/stdc++.h>
using namespace std;
string encryption(string s,int key)
{
        string t="";
        for(int i=0;i<s.size();i++)
        {
                t+=(s[i]-'A'+key)%26+'A';
        }
        return t;
}
string decryption(string s,int key)
{
        string t="";
        for(int i=0;i<s.size();i++)
        {
                t+=(s[i]-'A'-key+26)%26+'A';
        }
        return t;
}
int main()
{
        string s,temp;
        int key;
        cout << "Enter the message::";
        cin >> s;
        cout << "Enter key value";
        cin >> key;
        cout << "Encrypted message will be::";
        temp=encryption(s,key);
        cout << temp <<endl;
        cout << "Decrypted(Original) message will be::";
        cout << decryption(temp,key)<<endl;
        return 0;
}