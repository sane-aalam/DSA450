#include <iostream>
using namespace std;

// fuction for getting pivot value
int BinarySearchConcept(int arr[], int n,int k){
    int start = 0;
    int end = n -1;
    
    int mid;
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid] == k){
            return mid;
        }else if(arr[mid] < k){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

// main funciton 
int main(){
    int arr[5] = {7,8,9,10,11};
    int n = sizeof(arr)/sizeof(int);
    cout << "print size of array " << n << endl << endl;
    // key which we want to find in this array 
    int key;
    cout << "Enter the key value :" << endl;
    cin>> key;
    int find = BinarySearchConcept(arr,n,key);
    cout << "pivot element in index value : " << find  << endl << endl;
    return 0;
}