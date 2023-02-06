// Notes: Unbounded Knapsack (Repetition of items allowed)

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
          
        int t[N+1][W+1];
        
        for(int i=0; i<N+1; i++){
            for(int j =0; j<W+1; j++){
                if(i== 0 or j == 0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<N+1; i++){
            for(int j =1; j<W+1; j++){
        
                if(wt[i-1]<=j){
                    // you can include mulitple time items, if you are taking any elements
                    t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
                
            }
        }
        return t[N][W];
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}

