
/*
	if you know how to print LCS :

questions solve :
lcs me equal to include karte hai
but yahan eqal to ek bar include toh karna hai
or baki remaining charachter bhi include karna hai
	
*/


class Solution {
private:
string LCS(string str1, string str2, int m, int n)
    {
        // matrix for Memoization
        int t[m+1][n+1];
        
        // string for storing shortest common super subsequence
        string ind = "";
        
   
        for(int i = 0;i < m+1; ++i){
            for(int j = 0; j< n+1; ++j){
                // Initialising first row and first column of dp / t matrix to 0
                if(i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        
        for(int i = 1; i < m+1; ++i){
            for(int j = 1; j < n+1; ++j){
                if(str1[i-1] == str2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        // we want to actual string so use LCS print concept 
        int i = m, j = n;    
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ind.push_back(str1[i-1]); // put current character of LCS in ind
                --i;                     // reduce values of i,j
                --j;
            }
            else if(t[i][j-1] > t[i-1][j])
            {
                --j;                       // reduce value of j
            }
            else
            {
                --i;                       // reduce value of i 
            }
        }
        return ind;
    }

    public:
    string printLCS(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        return LCS(str1,str2,n,m);
    }
};
