// Questions :- you are give two string,your task to print the length of Longest common subsquence
#include <iostream>
using namespace std;
// Recursive code = base condtion(think valid smallest input ) + choice diagram( include + not include)
int LCS(string X, string Y, int n , int m){
    // base condtion
    if(n == 0 || m == 0){
        return 0;
    }
    // choice diagram 
    // if both are equal 
    if(X[n-1] == Y[n-1]){
        return 1 + LCS(X,Y,n-1,m-1);
    // not equal both are choice we have next equal they are,
    }else{
        return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
}

int main(){
    string X = "abcde";
    string Y = "adcde";

    int n = X.length();
    int m = Y.length() ;

    // Longest common subsquence function -:
    int result = LCS(X,Y,n,m);
    cout << endl;
    cout << "The Longest common subsquence ::" << result << endl;
    return 0;
}