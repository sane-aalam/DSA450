#include <iostream>
using namespace std;

void printArray(int arr[], int n){ 
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

 void sort012(int nums[], int n){
    
     int low = 0, mid = 0, high = n-1;
     
        while(mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
    }  
} 
     

int main(){
    int arr[] = {0,1,2,0,1,2,0,1,2};
    int n = sizeof(arr)/sizeof(int);

    cout << endl;
    cout << "Before the sort012 fuction apply:" << endl;
    printArray(arr,n);
    sort012(arr,n);
    cout << endl;
    cout << "After the sort012 function apply" << endl;
    printArray(arr,n);

    return 0;
}