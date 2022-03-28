/*Diffle-hellman example*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int p = 23;
    int g = 9;
    int x,y;

    cout<<"enter private key for first person(less than "<<p<<"): ";
    cin>>x;
    cout<<"enter private key for second person(less than "<<p<<"): ";
    cin>>y;

    int px,py;
    px = pow(g,x);
    px = px%p;
    py = pow(g,y);
    py = py%p;
    cout<<"\ngenerated key for first person: "<<px;
    cout<<"\ngenerated key for second person: "<<py<<"\n";

    int keyx = pow(py, x);
    keyx = keyx%p;
    int keyy = pow(px, y);
    keyy = keyy%p;

    cout<<"\nsecret key excanged for x: "<<keyx;
    cout<<"\nsecretkey excanged for y: "<<keyy<<"\n";

}