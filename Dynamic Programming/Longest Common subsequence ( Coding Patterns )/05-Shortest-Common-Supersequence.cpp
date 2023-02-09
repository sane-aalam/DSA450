#include<bits/stdc++.h>
using namespace std;

/* problem statemenet - lecture 24 ) Dp

    we know LCS problem
    1 ) here we are including all both string length
    2 ) reducing the common charcter length that why are using Lcs function 

*/

class Solution{
    // longest common subseqence [LCS CODE]
    private:
       int commonSubseq (string a, string b){
	   int n = a.size();
	   int m = b.size();
	   
	   int t[n+1][m+1];
	   
    // recursive base condtion convert into the insllization in topdown
	   for(int i=0; i<n+1; i++){
	       for(int j=0; j<m+1; j++){
	           if(i == 0 || j == 0){
	               t[i][j] = 0;
	           }
	       }
	   }
	   
	   
	   for(int i=1; i<n+1; i++){
	       for(int j=1; j<m+1; j++){
	           if(a[i-1] == b[j-1]){
	               t[i][j] = 1 + t[i-1][j-1];
	           }else{
	               t[i][j] = max(t[i][j-1],t[i-1][j]);
	           }
	       }
	   }
	   
	   return t[n][m];
	}
    public:
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        int lcs = commonSubseq(X,Y);
        // we will add length of boht of string then reduce longest common subsequence
        int ans = m + n - lcs;
        return ans;
    }
};

int main()
{   
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
	return 0;
}