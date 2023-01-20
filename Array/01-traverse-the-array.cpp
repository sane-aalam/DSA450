#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {1, 2, -6, -8, -93, 21};
    int n = sizeof(arr)/sizeof(int);

    // calling function
    printArray(arr,n);

    return 0;
}