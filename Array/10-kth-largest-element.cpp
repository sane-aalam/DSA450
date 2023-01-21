#include <bits/stdc++.h>
using namespace std;

// Method 1 : using brute force algorithm
//   1. sort the array
//   2. simply you can return arr[k-1] because the sorted array
    
int Kthlargest(int arr[], int l, int r, int k) {
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


int kthLargest(int arr[], int l, int r, int k) {
         
        //Min-Heap Initialization
        priority_queue<int, vector<int>, greater<int>> pq;
        
		//We push first k elements into min-heap
        for(int i=l; i<=k; i++) 
            pq.push(arr[i]);

        // now calculate for rest element
		//Now, if the element at top of min-heap is smaller, we remove it and add new element

        for(int i=k+1;i<=r;i++) {

            if(pq.top()<arr[i]) {
                pq.pop();
                
                pq.push(arr[i]);
            } 
        }
        
		//Return the top (smallest) of min-heap
        return pq.top();
}

int main(){
    int arr[5] = {10,4,3,20,15};
    int start = 0;
    int end = sizeof(arr)/sizeof(int);
    int k;

    cout << "largest element in the given :: " << endl;
    cin >> k;

    int largest_value = Kthlargest(arr,start,end,k);
    cout << "kth largest element is :: " << largest_value << endl;

    return 0;
}