// Variable decalaration

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    char c = 'A';
    string s = " This is a string value ! \n";

    cout << c << endl ;
    cout << s;
    cout << s;
    
    float f = 3.14159265358979;
    double d = 3.14159265358979;

    cout << setprecision(15);
    cout << "Float Value : " << f << endl;
    cout << "Double Value : " << d << endl;

    bool val = true;
    bool val1 = false ;

    cout << boolalpha << "Bool value : " << val1 << endl;

    return 0;
}