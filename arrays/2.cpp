// Find the smallest & largest value in an array
// length of array : 3, 5

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size = 5;
    int arr[size]={23,10,30,20,-18};
    int small = INT_MAX;    // holding max value +
    int large = INT_MIN;    /// holding min value -

    for (int i=0; i<5;i++)
    {
        if(arr[i]<small){
            small = arr[i];
        }
        if(arr[i]>large){
            large = arr[i];
        }
    }
    cout<<small<<" "<<large<<endl;
    return 0;
}

