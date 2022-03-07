#include <bits/stdc++.h>
using namespace std;

long int p, q, n, z, e, d, i, j, m, c, flag;
vector<int> v;

bool isPrime = true;

bool prime(long int num)
{
    for (i = 2; i <= (num / 2); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

long int findD(long int e)
{
    long int k = 1;
    while (1)
    {
        k = k + z;
        if (k % e == 0)
        {
            return (k / e);
        }
    }
}

void findE()
{
    for (j = 2; j < z; j++)
    {
        if (z % j != 0)
        {
            isPrime = prime(j);
            if (isPrime && j != p && j != q)
            {
                e = j;
                flag = findD(e);
                if (flag > 0)
                {
                    d = flag;
                    return;
                }
            }
        }
    }
}

string encryption(string plainText, int e, int n)
{
    v.clear();
    string encrypted;
    for (int a = 0; a < plainText.length(); a++)
    {
        // Encrytion Algorithm
        m = plainText[a] - 32; // Convert char to ASCII code
        long int k = 1;
        for (i = 0; i < e; i++)
        {
            k = k * m;
            k = k % n;
        }
        c = k;
        v.push_back(c);
        encrypted.push_back(char(c));
    }
    return encrypted;
}

string decryption(string encrypted, int d, int n)
{
    string decrypted;
    for (int a = 0; a < encrypted.length(); a++)
    {
        // Encrytion Algorithm
        c = v[a]; // Convert char to ASCII code
        long int k = 1;
        for (i = 0; i < d; i++)
        {
            k = k * c;
            k = k % n;
            // cout<<c<<" "<<k<<" ";
        }
        m = k;
        decrypted.push_back(k + 32);
        // cout<<k<<" ";
    }
    return decrypted;
}

vector<int> generateKey()
{
    cout << "Enter p(a prime number): ";
    cin >> p;
    cout << "Enter q(a prime number): ";
    cin >> q;

    n = p * q;
    z = (p - 1) * (q - 1);
    findE();
    return {e, d, n};
}

int main()
{
    string plainText;
    vector<int> key1 = generateKey();

    int pu1 = key1[0], pr1 = key1[1], n1 = key1[2];
    cout << "\npublic key for user1: " << pu1 << " private key for user1: " << pr1 << "\n";


    
    string R1;
    cout << "Enter R1 :(User2 also sends it to User1): ";
    cin >> R1;
    string encrypted2 = encryption(R1, pu1, n1);
    cout << "User2 sends encrypted R1 to User1 :" << encrypted2 << endl;
    string decrypted2 = decryption(encrypted2, pr1, n1);
    cout << "User1 decrypt it using " << pr1 << " and the decrypted text is: " << decrypted2 << endl;
    cout << "User1 sends decrypted R1 to User2 : " << decrypted2 << endl;

    if (decrypted2 != R1)
    {
        cout << "\nAuthentication invalid.";
    }
    else
    {
        cout << "\nAuthentication valid.";
    }
   
    return 0;
}