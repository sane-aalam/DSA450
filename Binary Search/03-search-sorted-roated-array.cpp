#include <iostream>
using namespace std;

// fuction for getting pivot value
int getting_pivot(int arr[], int n){
    int start = 0;
    int end = n - 1;

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

// fuction for getting pivot value
int BinarySearchConcept(int arr[],int s,  int n,int k){
    int start = s;
    int end = n - 1;
    // find the mid value in this array 
    int mid = start + (end-start)/2;
    while(start<=end){
        if(arr[mid] == k){
            return mid;
        }else if(arr[mid] < k){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
      
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    int arr[2] = {7,1};
    int n = sizeof(arr)/sizeof(int);
    cout << "print size of array " << n << endl << endl;
    int pivot = getting_pivot(arr,n);
    cout << "value of pivot element is : " << pivot << endl << endl;

    int key;
    cout << "Enter the key value :" << endl;
    cin>> key;

    if(arr[pivot] <= key && key <= arr[n-1]){
        // binary seach 2 rd line other wise else 1st line
       cout <<   BinarySearchConcept(arr,pivot,n,key);
    }else{
       cout <<    BinarySearchConcept(arr,0,pivot,key);
    }

    cout << endl << endl << "Everything is fine " << endl;

    return 0;
}