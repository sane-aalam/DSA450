#include <bits/stdc++.h>
using namespace std;

int intersection(int arr1[], int arr2[], int n, int m){

    int i = 0;
    int j = 0;

    while(i < n && j < m ){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else{
            j++;
        }
    }
}
int main(){
    int a[] = { 1, 3, 2, 3, 3, 4, 5, 5, 6 };
    int b[] = { 3, 2, 3, 5 };
 
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
 
    // sort the both of array so help to find out the common element easy 

    sort(a, a + n);
    sort(b, b + m);
 
    // Function call
    intersection(a, b, n, m);
}