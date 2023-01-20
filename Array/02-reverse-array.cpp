#include <iostream>
using namespace std;

void printArray(int arr[], int n){ 
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int n){
    int start = 0;
    int end = n - 1;

    while(start <= end){
        // you can use pre-define method and temp method (extra variable)
        // swap(arr[start], arr[end]); 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int arr[] = {1, 2,33,35,6,7,-1,0
    -93, 21};
    int n = sizeof(arr)/sizeof(int);

    // before swapping the array -> call the print function
    printArray(arr,n);

    // reverse array function calling here ->
    reverseArray(arr,n);
    cout << endl << endl;
    // after swapping the array -> call the print function
    printArray(arr,n);

    return 0;
}