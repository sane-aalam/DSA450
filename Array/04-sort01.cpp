#include <iostream>
using namespace std;

void printArray(int arr[], int n){ 
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

// Method : simple, you can use Two pointer algorithm

void sort01(int arr[], int n) {

        int start = 0; // starting index value of the array
        int end = n -1; // ending index value of the array

        while(start<end){
            // if starting element is 0 no problem increase index value
            if(arr[start] == 0 && start<end){
                start++;
            // if ending element is 1, no problem decrese index value
            }else if(arr[end] == 1 && start<end){
                end--;
            }else if(arr[start]!=0 && arr[end] != 1 && start<end){
                swap(arr[start], arr[end]);
                    start++;
                    end--;
            }
        }
}

int main(){
    int arr[] = {0,1,1,0,0,1};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr,n);
    sort01(arr,n);
    cout <<endl << endl;
    printArray(arr,n);

    return 0;
}