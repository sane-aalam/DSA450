#include <bits/stdc++.h>
using namespace std;

// Method - 1

// // Not perfect approach - when you have only postive element then you can use:
// int maximumSUM(int arr[]){
//     int sum = 0;
//     for(int i =0; i<sizeof(arr)/sizeof(int); i++){
//         sum = sum + arr[i];
//     }
//     return sum;
// }



// Method - 2

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// prefect approach - when you have negative and postive element then you can use kadane's algorithm 
// complexity
// TC - 0(N);
// SC - 0(1);
int maximumSUM(int arr[] , int n) {

        int currsum = 0;
        int maxsum = INT_MIN;

        for(int i = 0; i<n; i++){

            currsum = currsum + arr[i];

            if(currsum > maxsum){
                maxsum = currsum;
            }

            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxsum;
}


int main(){
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(int);
    int result = maximumSUM(arr,n);
    cout << "The Maximum Subarray is " << result;
    return 0;
}