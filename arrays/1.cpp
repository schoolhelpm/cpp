// create array to store 5 students marks

#include <iostream>
using namespace std;

int main(){
    //int stu[];      // empty array declared
    //int stu[5];     // declared array with no value
    int stu[5] = {40,50, 55, 67, 76};   // array with declared values
    
    // length of array : 0 to n-1
    cout<< stu[0]<<endl;
    
    // size of array -- memory it is holding for the array !
    cout<< sizeof(stu)<<endl;

    // printing value of array
    for(int i=0;i<5;i++)
    {
        cout<<stu[i]<<endl;
    }
    
    // edit/input values of arrays : arr[i] = value;
        for(int i=0;i<5;i++)
    {
        cout<<"Enter value for position "<<i<<": ";
        cin>>stu[i];
    }

    // printing value of array
    for(int i=0;i<5;i++)
    {
        cout<<stu[i]<<endl;
    }
    

    return 0;
}