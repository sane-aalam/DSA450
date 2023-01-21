#include <bits/stdc++.h>
using namespace std;

// Method 1 : using brute force algorithm
//   1. sort the array
//   2. simply you can return arr[k-1] because the sorted array
    
int kthSmallest(int arr[], int l, int r, int k) {
         sort(arr, arr + r);
         return arr[k-1];
}


// Method 2 : using Heap data structure 
//   1. use max heap 
//   2. if heap size is grether to the Kth value then pop the element ( heap )
//   3. finally you will have MAX HEAP top element is smallest 
    

// WHY HEAP DATA STRUCTURE 
// when you see kTh + smallest = use max heap ( always top element is maximum)
// when you see Kth + largest = use min heap  (always top element is minimum)


int kthSmallest(int arr[], int l, int r, int k) {
         
         // Creates a max heap
        priority_queue <int> pq;

        for(int i = l; i<=r; i++){
            pq.push(arr[i]);

            if(pq.size() > k){
                pq.pop();
            }
        }
        // return the top element
        return pq.top();
}

int main(){
    int arr[5] = {10,4,3,20,15};
    int start = 0;
    int end = sizeof(arr)/sizeof(int);
    int k;

    cout << "smallest element in the given" << endl;
    cin >> k;

    int kthsmallest_value = kthSmallest(arr,start,end,k);
    cout << "kth smallest element is :: " << kthsmallest_value << endl;

    return 0;
}