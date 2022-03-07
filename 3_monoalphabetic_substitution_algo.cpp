#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,char> map = {
        {'A', 'Q'}, {'B', 'W'}, {'C', 'E'}, {'D', 'R'}, {'E', 'T'}, {'F', 'Y'}, {'G', 'U'}, {'H', 'I'}, {'I', 'O'}, {'J', 'P'}, {'K', 'A'}, {'L', 'S'}, {'M', 'D'}, {'N', 'F'}, {'O', 'G'}, {'P', 'H'}, {'Q', 'J'}, {'R', 'K'}, {'S', 'L'}, {'T', 'Z'}, {'U', 'X'}, {'V', 'C'}, {'W', 'V'}, {'X', 'B'}, {'Y', 'N'}, {'Z', 'M'}
    };
        char msg[100];
        cout << "\nEnter The Message: \n";
        cin.getline(msg,100);
        char choice;
        cout<<"1. Encrypt message\n2. Decrypt message\n";
        cin>>choice;
        if(choice == '1'){
            for(int i=0; msg[i]!='\0'; i++){
                msg[i] = map[msg[i]];
            }
            cout<<"\nEncrypted Message: "<<msg<<"\n\n";
        }
        else if(choice == '2'){
            for(int i=0;msg[i]!='\0'; i++){
                for(auto &it:map){
                    if(it.second == msg[i]){
                        msg[i] = it.first;
                        break;
                    }
                }
            }
            cout<<"\nDecrypted Message: "<<msg<<"\n\n";
        }
    return 0;
}
