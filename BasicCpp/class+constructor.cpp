#include <iostream>

using namespace std;
class rect
{
private:
    int length;
    int breadth;

public:
    // rect(int l, int b) //constructor
    void initialize(int l , int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
    void changeLen(int l)
    {
        length = l;
    }
    void print()
    {
        cout << "length = " << length << endl;
        cout << "breadth = " << breadth << endl;
    }
};

int main()
{
    // rect r(10, 5); //call by constructor
    rect r;
    r.initialize(10, 5);
    r.print();
    r.area();
    cout << r.area() << endl;
    r.changeLen(20);
    r.print();

    return 0;
}