
//notes - himself distance  = 0 otherwise according to distance (1,2,3,4);   
//        hindi -  aapna kya krna ek matrix or duri ke adhar par value rakh kr ek matrix bane kra return kar deni hay
// tc = 0(n*m) sc= 0(n*m)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid) {
	     int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int row = 0; row < n; row++){
            for(int col =0; col<m; col++){
                if(grid[row][col] == 1){
                    q.push({{row,col},0});
                    vis[row][col] = 1;
                }else{
                    // grid cell contian 0 then put the 0 
                    vis[row][col] = 0;
                }
            }
        }
        
        //delta rows and cols array to traverse to U , R, D, L
	    int delRow[] = { -1  , 0 , +1 , 0 };
	    int delCol[] = { 0 , +1 , 0 , -1 };
	   // queue mein travel ker rhe hai
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int steps = q.front().second;
	       q.pop();
	       dis[row][col] = steps;
	       for(int i = 0; i<4; i++){
	           int nrow = row + delRow[i];
	           int ncol = col + delCol[i];
	           if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and
	            vis[nrow][ncol] == 0){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow , ncol} , steps + 1});
	            }
	       }
	   }
	   return dis;
        
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
