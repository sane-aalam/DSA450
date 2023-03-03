
/* 
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.


Approach simple-

1. we want to shorted path 
2. when we see shortest ( int matrix base problem ) keyword then 
 100% don't think too must- 
 directly use Dijstra algorithm

 Tc - ElogV 

*/

// start the question :
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        // create queue data structure                  
        queue<pair<int,pair<int,int>>> q;
        
        // find out the matrix size row wise and colum wise
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        
        
        dis[source.first][source.second] = 0;
        
        q.push({0,{source.first,source.second}});
        
        while(!q.empty()){
            int path = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
             // this conditon for what - when we will reach distination 
             if(row == destination.first && col == destination.second ){
                 return path;
            }
            
            
            // we can go 4-direction 
            int delrow[] = { -1,0,1,0 };
            int delcol[] = { 0,1,0,-1 };
            
            for(int index = 0; index < 4; index++){
                
                int newrow = delrow[index] + row;
                int newcol = delcol[index] + col;
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1
                 && path + 1 < dis[newrow][newcol]){
                     dis[newrow][newcol] = path + 1;
                     q.push({path+1,{newrow,newcol}});
                     
                 }
            }
        }
        // if you are not able to reach source to destination 
        // then you can return - 1
        return -1;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}