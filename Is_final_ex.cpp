#include<iostream>
#include<math.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

string encrypt1(string str, vector<pair<char,char> > &map) {
    string encryptedString;
    //Caesar Cipher
    int n = str.size(), k = 5;
    for (int i = 0; i < n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int temp = (str[i] - 'A' + k) % 26;
            char ch = 'A' + temp;
            encryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int temp = (str[i] - 'a' + k) % 26;
            char ch = 'a' + temp;
            encryptedString += ch;
        }
        else {
            encryptedString += str[i];
        }
    }
    cout<<"The string after applying Ceaser Cipher: "<<encryptedString<<endl;
    //Monoalphabetic Substitution Algo
    str = encryptedString;
    encryptedString.clear();
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int idx = str[i] - 'A';
            char ch = map[idx].first;
            encryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int idx = str[i] - 'a';
            char ch = map[idx].second;
            encryptedString += ch;
        }
        else {
            encryptedString += str[i];
        }
    }
    cout<<"The string after applying Monoalphabetic Substitution Algorithm: "<<encryptedString<<endl;
    //ASCII conversion
    str = encryptedString;
    encryptedString.clear();
    for(int i=0;i<n;i++) {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) {
            int asciiVal = (int)str[i];
            string tmp = to_string(asciiVal);
            if(tmp.size() == 2) {
                tmp = '0' + tmp;
            }
            encryptedString += tmp;
        }
        else {
            encryptedString += str[i];
        }
    }
    cout<<"The string after applying ASCII conversion: "<<encryptedString<<endl<<endl;
    return encryptedString;
}

string encrypt2(string str, string &key, vector<vector<pair<char,char> > > &map, vector<int> &rowPerm, vector<int> &colPerm) {
    string encryptedString;
    //Polyalphabetic Substitution Algo
    int n = str.size();
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int row = str[i] - 'A';
            int col = key[i] - 'a';
            char ch = map[row][col].first;
            encryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int row = str[i] - 'a';
            int col = key[i] - 'a';
            char ch = map[row][col].second;
            encryptedString += ch;
        }
        else {
            encryptedString += str[i];
        }
    }
    cout<<"The string after applying Polyalphabetic Substitution Algorithm: "<<encryptedString<<endl;
    //Double Transposition Cipher
    str = encryptedString;
    encryptedString.clear();
    int row = sqrt(n);
    if(row*row!=n) {
        row++;
    }
    int col = row;
    vector<vector<char> > mat(row, vector<char>(col));
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0;j<col;j++) {
            if(k==n) {
                mat[i][j] = '#';
                continue;
            }
            mat[i][j] = str[k++];
        }
    }
    vector<vector<char> > temp(row, vector<char>(col));
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            temp[i][j] = mat[rowPerm[i]][j];
        }
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            mat[i][j] = temp[i][colPerm[j]];
        }
    }
    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col;j++) {
            encryptedString += mat[i][j];
        }
    }
    cout<<"The string after applying Double Transposition Cipher: "<<encryptedString<<endl;
    //8-bit Binary Conversion
    str = encryptedString;
    encryptedString.clear();
    n = str.size();
    for(int i=0;i<n;i++) {
        if(str[i] != '*' && str[i] != '#') {
            int asciiVal = (int)str[i];
            string tmp;
            while(asciiVal) {
                int rem = asciiVal % 2;
                tmp += to_string(rem);
                asciiVal /= 2;
            }
            if(tmp.size() < 8) {
                int rem = 8 - tmp.size();
                string t(rem,'0');
                tmp = tmp + t;
            }
            reverse(tmp.begin(),tmp.end());
            encryptedString += tmp;
        }
        else {
            encryptedString += str[i];
        }
    }
    cout<<"The string after applying 8-bit Binary conversion: "<<encryptedString<<endl<<endl;
    return encryptedString;
}

string decrypt1(string str, vector<pair<char,char> > &key) {
    string decryptedString;
    //ASCII conversion
    int n = str.size();
    for(int i=0;i<n;) {
        if(str[i] == '*') {
            decryptedString += str[i++];
        }
        else {
            string temp = str.substr(i,3);
            int asciiVal = stoi(temp);
            char ch = (char)asciiVal;
            decryptedString += ch;
            i+=3;
        }
    }
    cout<<"The string after applying ASCII conversion: "<<decryptedString<<endl;
    //Monoalphabetic Substitution Algo
    str = decryptedString;
    decryptedString.clear();
    n = str.size();
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int idx = str[i] - 'A';
            char ch = key[idx].first;
            decryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int idx = str[i] - 'a';
            char ch = key[idx].second;
            decryptedString += ch;
        }
        else {
            decryptedString += str[i];
        }
    }
    cout<<"The string after applying Monoalphabetic Substitution Algorithm: "<<decryptedString<<endl;
    //Caesar Cipher
    str = decryptedString;
    decryptedString.clear();
    int k = 5;
    for (int i = 0; i < n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int temp = (str[i] - 'A' - k + 26) % 26;
            char ch = 'A' + temp;
            decryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int temp = (str[i] - 'a' - k + 26) % 26;
            char ch = 'a' + temp;
            decryptedString += ch;
        }
        else {
            decryptedString += str[i];
        }
    }
    cout<<"The string after applying Ceaser Cipher: "<<decryptedString<<endl<<endl;
    return decryptedString;
}

string decrypt2(string str, string &key, vector<vector<pair<char,char> > > &map, vector<int> &rowPerm, vector<int> &colPerm) {
    string decryptedString;
    //8-bit Binary Conversion
    int n = str.size();
    for(int i=0;i<n;) {
        if(str[i] == '*' || str[i] == '#') {
            decryptedString += str[i++];
        }
        else {
            string tmp = str.substr(i,8);
            int num = 0, prod = 1;
            for(int j=7;j>=0;j--) {
                num += (tmp[j] - '0') * prod;
                prod *= 2;
            }
            char ch = (char)num;
            decryptedString += ch;
            i+=8;
        }
    }
    cout<<"The string after applying 8-bit Binary conversion: "<<decryptedString<<endl;
    //Double Transposition Cipher
    str = decryptedString;
    decryptedString.clear();
    n = str.size();
    int row = sqrt(n);
    if(row*row!=n) {
        row++;
    }
    int col = row;
    vector<vector<char> > mat(row, vector<char>(col));
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0;j<col;j++) {
            mat[i][j] = str[k++];
        }
    }
    vector<vector<char> > temp(row, vector<char>(col));
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            temp[i][colPerm[j]] = mat[i][j];
        }
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            mat[rowPerm[i]][j] = temp[i][j];
        }
    }
    for (int i = 0; i < row;i++) {
        bool flag = true;
        for (int j = 0; j < col;j++) {
            if(mat[i][j]=='#') {
                flag = false;
                break;
            }
            decryptedString += mat[i][j];
        }
        if(!flag) {
            break;
        }
    }
    cout<<"The string after applying Double Transposition Cipher: "<<decryptedString<<endl;
    //Polyalphabetic Substitution Algo
    str = decryptedString;
    decryptedString.clear();
    n = str.size();
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<='Z') {
            int c = key[i] - 'a';
            char ch;
            for(int j=0;j<26;j++) {
                if(map[j][c].first==str[i]) {
                    ch = 'A' + j;
                    break;
                }
            }
            decryptedString += ch;
        }
        else if(str[i]>='a' && str[i]<='z') {
            int c = key[i] - 'a';
            char ch;
            for(int j=0;j<26;j++) {
                if(map[j][c].second==str[i]) {
                    ch = 'a' + j;
                    break;
                }
            }
            decryptedString += ch;
        }
        else {
            decryptedString += str[i];
        }
    }
    cout<<"The string after applying Polyalphabetic Substitution Algorithm: "<<decryptedString<<endl<<endl;
    return decryptedString;
}

int main() {
    string str;
    cout << "\nEnter the string: ";
    getline(cin,str);
    int len = str.size();
    for(int i=0;i<len;i++) {
        if(str[i] == ' ') {
            str[i] = '*';
        }
    }
    //Divide string into 2 parts
    int len1 = (len + 1)/2;
    string part1 = str.substr(0,len1);
    string part2 = str.substr(len1);
    cout<<"\nThe first part of the string is: "<<part1<<endl;
    cout<<"The second part of the string is: "<<part2<<endl;
    //Monoalphabetic Substitution Algo Req
    vector<pair<char,char> > map(26);
    for(int i=0;i<26;i++) {
        map[i].first = 'A'+i;
        map[i].second = 'a'+i;
    }
    random_shuffle(map.begin(),map.end());
    vector<pair<char,char> > key(26);
    for(int i=0;i<26;i++) {
        int idx = map[i].first - 'A';
        key[idx].first = 'A'+i;
        key[idx].second = 'a'+i;
    }
    //Polyalphabetic Substitution Algo Req
    string keyString = "hardtocrack";
    int k = 0, n = str.size();
    string modifiedKey;
    for(int i=0;i<n;i++) {
        modifiedKey += keyString[k++];
        if(k == keyString.size()) {
            k = 0;
        }
    }
    int rowStart = 0;
    vector<vector<pair<char,char> > > map1(26,vector<pair<char,char> > (26));
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            int idx = (rowStart+j)%26;
            map1[i][j].first = 'A' + idx;
            map1[i][j].second = 'a' + idx;
        }
        rowStart++;
    }
    //Double Transposition Cipher Req
    int row = sqrt(len/2);
    if(row*row!=n) {
        row++;
    }
    int col = row;
    vector<int> rowPerm(row);
    vector<int> colPerm(col);
    for(int i=0;i<row;i++) {
        rowPerm[i] = i;
    }
    for(int i=0;i<col;i++) {
        colPerm[i] = i;
    }
    random_shuffle(rowPerm.begin(), rowPerm.end());
    random_shuffle(colPerm.begin(), colPerm.end());
    //Encryption
    cout<<"\nEncryption Starts:\n";
    part1 = encrypt1(part1,map);
    part2 = encrypt2(part2,modifiedKey,map1,rowPerm,colPerm);
    string encryptedString = part1 + part2;
    cout << "The encrypted string is: " << encryptedString << endl;
    //Decryption
    cout<<"\nDecryption Starts:\n";
    string decryptedString = decrypt1(part1,key) + decrypt2(part2,modifiedKey,map1,rowPerm,colPerm);
    for(int i=0;i<len;i++) {
        if(decryptedString[i] == '*') {
            decryptedString[i] = ' ';
        }
    }
    cout << "The decrypted string is: " << decryptedString << endl;
    return 0;
}