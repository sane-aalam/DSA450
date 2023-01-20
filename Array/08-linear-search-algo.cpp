#include <iostream>
using namespace std;

int Linearsearchalgo(int arr[], int n , int key){
    
    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    // if element is not present in the array then we can return
    return -1;
}

int main(){
    int arr[] = {1, 2, -6, -8, -93, 21};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cout << "Enter the key value" << endl;
    cin >> key;

    int indexvalue = Linearsearchalgo(arr,n,key);
    cout << "index value of the element " << indexvalue << endl;

    return 0;
}