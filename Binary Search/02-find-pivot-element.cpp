#include <iostream>
using namespace std;

// fuction for getting pivot value
int getting_pivot(int arr[], int n){
    int start = 0;
    int end = n -1;

    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[0] <= arr[mid]){
            start = mid + 1;
        }else{
            end = mid;
        }
        // remember aftering updtaing start value and ending value 
        // you should be checked you can update the mid 
        mid = start + (end-start)/2;
    }
    return start;
}


int main(){
    int arr[5] = {7,9,1,2,3};
    int n = sizeof(arr)/sizeof(int);
    cout << "print size of array " << n << endl << endl;
    int pivotElement = getting_pivot(arr,n);

    cout << "pivot element in index value : " << pivotElement  << endl << endl;

    return 0;
}