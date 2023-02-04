#include <iostream>
using namespace std;


// Appraoch- privours questions, we have solved subset sum present or not!
// but in this question, we want all subset (how many subset possible )
// output : count of subset possible of give array

// we want to count so int value return type int 

int CountSubsetSum(int arr[], int n , int sum){
    // create matrix for topdown approach 
    int dp[n+1][sum+1];
    
    // we want subset is present are not ):
    // we are create matrix and set first row and first colum according to choice diagra

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}


int main(){
    int arr[] = {1,3,4,8,8};
    int n = 5; // here n is size of value array
    int sum = 8; // give sum 

    cout << endl;
    cout << "Output " << CountSubsetSum(arr,n,sum);
    cout << endl;
    return 0;
}