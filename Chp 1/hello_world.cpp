// hello_world.cpp
/* 
#include <iostream>  → Get tools for input/output
using namespace std;  → Make std tools easier to use

int main()            → Program starts here
{
    std::cout << "Hello, World!";
    
    cout<< "Hello, World!";              → Print something
    cin >> "Enter a value: ";
    
    return 0           → Program finished
}

#include <iostream>
using namespace std;

int main() //main()
{
    int a;  // declaring a variable name & data type
    // a = input("Enter the value - ")
    cout << "Enter the value : ";    // print output info <-- >> <--
    cin >> a;
    cout << a;

    return 0;                   // terminate program
}

Executing the file - 
g++ hello_world.cpp -o hello_world
./hello_world

*/

#include <iostream>
using namespace std;

int main() //main()
{
    double a, b, sum;
    printf("Hello, World!");    // print output info <-- >> <--
    cout << " Enter value of first variable :  ";
    cin >> a;
    cout << "Enter value of 2nd variable : ";
    cin >> b;

    sum = (5/100.0)*b;

    // print('the sum of both values are : ', sum)
    cout << "The sum value is : "<< sum;    // << a+b;
    
    return 0;
}