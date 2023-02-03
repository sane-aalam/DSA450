#include <iostream>
using namespace std;

// Topdown Appraoch 
//  we totally remove recusive calling process

// 1. create matrix and create matrix using recursive base condtion
// 2. recursive code convert into the iterative code


// RE-used sub sum problem code here--
bool SubsetSum(int arr[], int n , int sum){

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

    int arr[] = {1,5,10,5};
    int n = 4; // here n is size of value array


/* variation of the 0-1 knapscak || TOP DOWN APRROACH 

 A) create a matrix and installization of matrix
 B) if even 22 = 11 + 11 equal division possible otherwise no division possible
 C) if you have one part ( means you have one sum then simply findout the second sum )
 if present then return true 
 d) otherwise false;

 ------------------- explain simple-------------
 simple think about sum = 30 
 if you find out the sum/2 = 15 
 means you have one sum = 15 

 then you know how to solve subset sum problem in geeksforgeek
 so re-used the code
 */

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + arr[i];
    }    
    
    bool result;
    if(sum%2 != 0){  // if sum of array is odd then 
            result =  false;
    }else{           // else sum of array is even if even then possible equal both part of the array
            result = SubsetSum(arr,sum/2,n); // subset sum function calls
    }

    cout << "The final result of the questions " << result << endl;
    return 0;
}