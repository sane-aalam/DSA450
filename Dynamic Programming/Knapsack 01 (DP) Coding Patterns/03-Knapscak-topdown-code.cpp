
#include <iostream>
using namespace std;

// Topdown Appraoch 
//  we totally remove recusive calling process

// 1. create matrix and installation matrix using recursive base condtion
// 2. recursive code convert into the iterative code

int knapscak01(int values[], int wieght[] , int W, int n){

      int dp[n+1][W+1];

      for(int i =0; i<n+1; i++){
          for(int j =0; j<W+1; j++){
              if(i==0 || j == 0){
                  dp[i][j] = 0;
              }            
          }
      }
      
        for(int i =1; i<n+1;i++){
           for(int j =1; j<W+1;j++){
                // include and not include 
               if( wieght[i-1] <=j){
                   dp[i][j] = max((values[i-1]+dp[i-1][j-wieght[i-1]]), dp[i-1][j]);
               } else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }

       return dp[n][W];
}



int main(){

    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    int n = 3; // here n is size of value array
    int W = 4; // W is the capacity of the array

    int maximum_Profit = knapscak01(values,weight,W,n);
    cout << endl;
    cout << "The maximum Profit "  << maximum_Profit << endl;
    cout << endl;

    return 0;
}