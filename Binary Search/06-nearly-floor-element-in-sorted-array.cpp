// question - geekforgeek - 02
// floor element in sorted array 
// (7 near 6 and 5 near 4)
// 7.5 floor = 7

#include <iostream>
using namespace std;

int FloorElement(int *arr, int size,int k){
    int start = 0;
    int end = size - 1;
    
    int mid = start + (end - start)/2;
    int result = -1;

    while(start<=end){
        if(arr[mid == k]){
            return arr[mid];
        }
        if(arr[mid] < k){
            result = arr[mid];
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return result;
}


int main(){
    int arr[8] = {1,2,3,8,10,12,19,21};
    int size = 8;
    int search;
    cout << "Enter the number which you want to search:" << endl;
    cin>> search ;
    int find = FloorElement(arr,size,search);
    cout << "index value of element " << find << endl;
}