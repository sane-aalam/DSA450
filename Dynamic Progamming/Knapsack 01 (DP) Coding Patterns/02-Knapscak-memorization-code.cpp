#include <iostream>
using namespace std;

// MEMORIZATION = RECURSIVE CODE + TABLE USING -1 

int knapscak01(int values[], int wieght[] , int W, int n){

    // create matrix and installization using -1 complete matrix 
    int dp[n+1][W+1];

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<W+1; j++){
            dp[i][j] = -1;
        }
    }
    
    // base condition
    if(n == 0 || W == 0){
        return 0;
    }

    // if this value is already store in the matrix means- this is not -1 so return this value
    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wieght[n-1] <= W){
      dp[n][W] = max ( values[n-1] + 
      knapscak01(values, wieght, W - values[n-1], n-1), 
      knapscak01(values,wieght,W,n-1));
      return dp[n][W];
    }else{
        dp[n][W] = knapscak01(values,wieght,W,n-1);
        return dp[n][W];
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