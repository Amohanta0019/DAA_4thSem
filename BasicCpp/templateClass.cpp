#include <iostream>

using namespace std;
template <class T>
class arithmatic
{
    private:
        T a;
        T b;
    public:
        arithmatic(T a, T b);
        T add();
        T sub();
};

template <class T>
arithmatic <T> :: arithmatic (T a, T b){
    this-> a = a;
    this-> b = b;
}
template <class T>
T arithmatic <T> :: add(){
    T c;
    c = a+b;
    return c;
}
template <class T>
T arithmatic <T> :: sub(){
    T c;
    c = a-b;
    return c;
}

int main()
{
    // cout<<"Hello World";
    arithmatic <int> ar(10,5);
    cout<<"addition is -->"<<ar.add()<<endl;
    cout<<"substraction is -->"<<ar.sub()<<endl;
    
    arithmatic <float> ar1(10.0 , 4.0);
    cout<<"addition is -->"<<ar1.add()<<endl;
    cout<<"substraction is -->"<<ar1.sub()<<endl;

    return 0;
}
/*
addition is -->15
substraction is -->5
addition is -->14
substraction is -->6
*/