
#include <iostream>
using namespace std;

// Topdown Appraoch 
//  we totally remove recusive calling process

// 1. create matrix and create matrix using recursive base condtion
// 2. recursive code convert into the iterative code


bool SubsetSum(int arr[], int n , int sum){
    // create matrix for topdown approach 
    int dp[n+1][sum+1];
    
    // we want subset is present are not ):
    // we are create matrix and set first row and first colum according to choice diagra

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    /*
    notes -  why we are starting i = 1 ?
    1. we have done 1 row and 2 colum for
    set base condtion into initialization!
    2.same pattern used here 01-knapscak so don't worry about :
    */
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}



int main(){
    int arr[] = {1,2,3};
    int n = 3; // here n is size of value array
    int sum = 77; // W is the capacity of the array

    cout << endl;
    cout << "Output " << SubsetSum(arr,n,sum);
    cout << endl;
    return 0;
}