#include<bits/stdc++.h> 
using namespace std; 

/*

  if i apply appni matching algoritm - 
  
  then it's same problem just like Flood fill agoritm and rottern oranges
  
  - tips for you
  - always remember the pattern 
  - jo tumhe aata usi se socho 


 Approach - 
 1- take visted array to contorl - we don't want to go again same nodes ( element)
 2- if we use DFS, it will take lot of time- it's go depth wise 
    so i choose BFS algorithm, works level wise 
    it will take miminum to change 0 to 1 value
    
3- in order to apply bfs algorithm 
   - need queue 
   - in this queue we can store row,col,time
 
4 - for every interation we wil incease the time ):


*/

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        vector<vector<int >> vis(N,vector<int>(M,0));
    
        queue<pair<pair<int,int>,int>> q;
        q.push({{x-1,y-1},0}); // push the node 1 with time 0 starting phase
    
        // mark visted
        vis[x-1][y-1] = 1;
        
        int count = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            count = q.front().second;
            
            q.pop();
            
            // we want to 4-directions 
            int delrow[4] = { -1,0,1,0};
            int delcol[4] = { 0,1,0,-1};
            
            for(int index = 0; index< 4; index++){
                int newrow = delrow[index] + row;
                int newcol = delcol[index] + col;
                
                // we will follow 3 condition 
                // - valid range 
                // - it already not vistied
                // - cell contain 0 node 
                
                if(newrow >= 0 && newrow < N && newcol >= 0 && newcol < M 
                && vis[newrow][newcol]== 0 ){
                    q.push({{newrow,newcol},count+1});
                    vis[newrow][newcol] = 1;
                }
            }
        }
        return count;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 