#include <bits/stdc++.h>
using namespace std;


// GEEKSFROGEEK = https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        // what if give source is contain zero 0 not 1
        // not possilbe to reach source to distination
        if(A[0][0] == 0) 
            return -1;

        // create queue data and push into starting row and starting col into the queue and 
        // intially paht = 0 
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}}); 

        // create the visted 2d array and mark visted 
        vector<vector<int>> vis(N,vector<int>(M,0));
        vis[0][0] = 1;
        
        // perfom BFS and dijstra algorithm
        
        while(!q.empty()){
            int path = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            // chekout the souce indexes reach to the distination 
            if(row == X && col == Y){
                return path;
            }
            
            // go the 4-direction
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int way = 0; way < 4; way++){
                int newrow = delrow[way] + row;
                int newcol = delcol[way] + col;
                
                if(newrow >= 0 && newrow < N && newcol >= 0 && newcol < M && 
                !vis[newrow][newcol] && A[newrow][newcol] == 1){
                    vis[newrow][newcol] = 1;
                    q.push({path+1,{newrow,newcol}});
                } 
            }
            
        }
        // not possible to reach source to distanation 
        return - 1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}