#include<iostream>
using namespace std;
// array are alwaya access by address , not value
// void func(int a[ ] , int n){ //pointer to an array
// void func(int *a , int n){ // pointer to integer
//     // cout<<sizeof(a) / sizeof(int)<<endl;// gives size of pointer not array, a
//     // for(int x : a)
//     // cout<<a<<endl;  we can noy=t use for each loop in pointer
//     // for (int i = 0; i < n; i++)
//     // {
//         // cout<<a[i]<<endl;
//     // }
//     a[0] = 12;    
// }
int * fun(int size){
    int *p;
    p = new int [size];
    for ( int i  = 0; i < size; i++)
    {
        p[i] = i + 1;
        return p;
    }
    
}

int main (void)
{
    // int a[] = {2,4,6,8,10};
    // for(int x : a)
    // cout<<x<<"  ";
    // cout<<endl;
    // int n = 5;
    // func(a,n);
    // for(int x : a)
    // cout<<x<<"  ";

    int * ptr  , sz = 5;
    ptr = fun(sz);
    for (int i = 0; i < sz; i++)
    {
        cout<<ptr[i]<<endl;
    }
    
    

return 0;
}