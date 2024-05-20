#include<iostream>
using namespace std;
int main (void)
{
    int x = 10;
    // int &y = x;
    //cout<<"y = "<<y<<endl; // O.P :- 10
    // cout<<"x = "<<x<<endl; // O.P :- 10
    // cout<<"&y = "<<&y<<endl; // O.P :- 0x61ff08
    // cout<<"&x = "<<&x<<endl; // O.P :- 0x61ff08
    x = x++;
    // cout<<x<<endl; // O.P :- 11
    // cout<<y<<endl; // O.P :- 11



return 0;
}