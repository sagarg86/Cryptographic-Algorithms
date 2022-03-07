//DOUBLE TRANSPOSITION CIPHER
#include <bits/stdc++.h>
using namespace std;

string encrypt(string s,string str,vector <int> row,vector <int> col)
{
    string result,res;
    int x=0;
    char arr[row.size()][col.size()];
    for(int i=0;i<row.size();i++)
        for(int j=0;j<col.size();j++)
        {
            if(x>=str.length())
                arr[i][j]='#';
            else
            {
                arr[i][j]=str[x];
                x++;
            }
        }
    x=0;
    for(int i=0;i<row.size();i++)
        for(int j=0;j<col.size();j++)
            res.push_back(arr[row[i]-1][col[j]-1]);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>96&&s[i]<123)
        {
            result.push_back(res[x]);
            x++;
        }
        else if(s[i]!='.')
            result.push_back(s[i]);
    }
    while(x!=res.length())
    {
        result.push_back(res[x]);
        x++;
    }
    return result;
}

string decrypt(string s,string str,vector <int> row,vector <int> col)
{
    string result;
    char arr[row.size()][col.size()];
    int x=0;
    for(int i=0;i<row.size();i++)
        for(int j=0;j<col.size();j++)
        {
            arr[row[i]-1][col[j]-1]=str[x];
            x++;
        }
    x=0;
    int i=0,j=0;
    while(x<s.length())
    {
        if(j>=col.size())
        {
            i++;
            j=0;
        }
        if(s[x]>96&&s[x]<123)
        {
            result.push_back(arr[i][j]);
            j++;
        }
        else if(s[x]!='#')
            result.push_back(s[x]);
        x++;
    }
    return result;
}

int main()
{
    string result,s,str;
    int row_no,col_no;
    cout<<"Enter the message to be encrypted(in lowercase only)"<<endl;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='#')
            str.push_back(s[i]);
        else if(s[i]>96&&s[i]<123)
            str.push_back(s[i]);
    }
    if((int)sqrt(str.length())==sqrt(str.length()))
    {
        col_no=(int)sqrt(str.length());
        row_no=(int)sqrt(str.length());
    }
    else
    {
        if(str.length()>((int)sqrt(str.length())*((int)sqrt(str.length())+1)))
        {
            col_no=(int)sqrt(str.length())+1;
            row_no=(int)sqrt(str.length())+1;
        }
        else
        {
            col_no=(int)sqrt(str.length())+1;
            row_no=(int)sqrt(str.length());
        }
    }
    cout<<"The number of rows and columns are "<<row_no<<" and "<<col_no<<endl;
    vector <int> row(row_no),col(col_no);
    cout<<"Enter the row permutation."<<endl;
    for(int i=0;i<row_no;i++)
        cin>>row[i];
    cout<<"Enter the column permutation."<<endl;
    for(int i=0;i<col_no;i++)
        cin>>col[i];
    cout << "Encrypted Message will be :";
    result=encrypt(s,str,row,col);
    cout<<result<<endl;
    cout<<"Decrypted Message will be :"; 
    result=decrypt(s,str,row,col);
    cout<<result<<endl;
    
    return 0;
}
