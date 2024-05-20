#include<iostream>
using namespace std;
struct rectangle{
    int length;
    int breadth;
};
int main (void)
{

    // int a = 10;
    // int *p;
    // p = &a;
    // cout<<a<<endl; // O.P :- 10
    // cout<<*p<<endl; // O.P :- 10
    // cout<<p<<endl; // O.P :- 0x61ff08
    // cout<<&a<<endl; // O.P :- 0x61ff08
    // cout<<&p<<endl; // O.P :- 0x61ff08

    // ACCESS ARRAY BY POINTER:-
    // --------------------------
    // int A[5] = {1,2,3,4,5};
    // int *p;
    // p = A;
    // p = &A[0];
    // p = &A;-----> ERROR
    // for (int i = 0; i < 5; i++)
    // {
        // cout<<A[i]<<endl;
        // cout<<p[i]<<endl; // O.P :- 1 2 3 4 5 
    // }
    
    // int *p;
    // p = new int[5];
    // p[0] = 10;
    // p[1] = 11;
    // p[2] = 12;
    // p[3] = 13;
    // p[4] = 14;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<p[i]<<endl;  // O.P :- 10 11 12 13 14
    // }
    
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct rectangle *p5;
    cout<<sizeof(p1)<<endl; // O.P :- 4
    cout<<sizeof(p2)<<endl; // O.P :- 4
    cout<<sizeof(p3)<<endl; // O.P :- 4
    cout<<sizeof(p4)<<endl; // O.P :- 4
    cout<<sizeof(p5)<<endl; // O.P :- 4



    






    
return 0;
}