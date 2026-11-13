// Binary Search

#include <iostream>
using namespace std;

int linearsearch(int arr[], int sz, int target){
    for(int i=0;i<sz;i++){
        if(arr[i]==target){
            return i;   // index value return
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,2,34,5,65,7};
    int sz = 6;
    int target = 65;
    int value;
    value = linearsearch(arr,sz,target);

    if (value > 0){
        cout<<"Index Value : "<<value<<endl;
    }
    else{
        cout<<"Value not found! "<<endl;
    }
    return 0;
}