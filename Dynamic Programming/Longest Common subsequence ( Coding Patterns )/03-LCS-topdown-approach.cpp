// Questions :- you are give two string,your task to print the length of Longest common subsquence
#include <iostream>
using namespace std;
// Recursive code = base condtion(think valid smallest input ) + choice diagram( include + not include)
int LCS(string X, string Y, int n , int m){

    int dp[n+1][m+1];

    // recursive base condtion convert into the insllization in topdown
    for(int i= 0; i<n+1; i++){
        for(int j = 0; j<m+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    // choice diagram with lopp
    for(int i= 1; i<n+1; i++){
        for(int j = 1; j<m+1; j++){

            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string X = "abcdd";
    string Y = "awedd";

    int n = X.length();
    int m = Y.length() ;

    // Longest common subsquence function -:
    int result = LCS(X,Y,n,m);
    cout << endl;
    cout << "The Longest common subsquence ::" << result << endl;
    return 0;
}