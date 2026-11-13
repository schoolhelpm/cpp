// declare pointer

#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int *p = &x;   // p stores address of x
    cout << p << endl;     // prints address
    cout << *p << endl;    // dereference: prints value at that address -> 10
    return 0;
}