// Questions :- you are give two string,your task to print the length of Longest common subsquence
#include <iostream>
using namespace std;
// Recursive code = base condtion(think valid smallest input ) + choice diagram( include + not include)
int LCS(string X, string Y, int n , int m){

    int dp[n+1][m+1];
    for(int i= 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            dp[i][j] = -1;
        }
    }
    // base condtion
    if(n == 0 || m == 0){
        return 0;
    }

    if(dp[n-1][m-1] != -1){
        return dp[n][m];
    }

    // choice diagram 
    if(X[n-1] == Y[n-1]){
        return dp[n][m] = 1 + LCS(X,Y,n-1,m-1);
    }else{
        return dp[n][m] =  max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
}

int main(){
    string X = "abcdd";
    string Y = "abedd";

    int n = X.length();
    int m = Y.length() ;

    // Longest common subsquence function -:
    int result = LCS(X,Y,n,m);
    cout << endl;
    cout << "The Longest common subsquence ::" << result << endl;
    return 0;
}