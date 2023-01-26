
#include <iostream>
using namespace std;

int NearlySearch(int *arr, int size,int k){
    int start = 0;
    int end = size - 1;
    
    int mid = start + (end - start)/2;

    while(start<=end){
        if(arr[mid] == k){
            return mid;
        }else if(arr[mid + 1] == k && mid + 1 <=end){
            return mid + 1;
        }else if(arr[mid - 1 ] == k && mid - 1 >= start){
            return mid - 1;
        }else if(arr[mid] < k){
            start = mid + 2;
        }else{
            end = mid - 2;
        }
        mid = start + (end - start)/2;
    }
    return - 1;
}


int main(){
    int arr[5] = {5,10,30,10,40};
    int size = 5;
    int search;
    cout << "Enter the number which you want to search:" << endl;
    cin>> search ;
    int find = NearlySearch(arr,size,search);
    cout << "index value of element " << find << endl;
}