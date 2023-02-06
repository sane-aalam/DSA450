// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* 
    1 ) problem
    
    Approach to solve :
    a ) problem statement
    b ) mathcing = here mathcing with unbound knapscak problme when we divide rod then multiple occances comes
    c ) code variabtion - same to unbound knapscak
    
   ------------- matching algorithm used here ----------
   
    Lenth array = wieght array
    price array =  val array 
    N ( length of rod ) = W ( capacity of knapscak)
    
    some case they doest give you 
    length array then you have N = 8 (length)
    that time you will crate lenght array 
    then same to same problem unbound knapscak 
    
    only name change
    Soni = Sham
    Ansika = Vansika
    Sane = Jane 
    Ram = Shaym 
    so that's it

    code : 
    you can change the name but code and conpet no change 
*/



class Solution{
// Topdown Appraoch 
//  we totally remove recusive calling process

// 1. create matrix and installation matrix using recursive base condtion
// 2. recursive code convert into the iterative code

private:
int knapscak(int values[], vector<int> Len, int W, int n){

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
                // unbounded kanpscak (n-1 not)
                // we can take (N) element again
               if( Len[i-1] <=j){
                   dp[i][j] = max((values[i-1]+dp[i][j-Len[i-1]]), dp[i-1][j]);
               } else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
}
  public:
    int cutRod(int price[], int n) {
        // start code here 
        vector<int> lenarr;
        for(int i = 1; i<=n; i++){
            lenarr.push_back(i);
        }
        
        int size = lenarr.size();
        
        return knapscak(price,lenarr,size,n); // unbounded knapscak function called 
    }
};
// main functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}