#include <bits/stdc++.h>
using namespace std;

// NOTE - if you are able to come back to same node then you can graph have cycle

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int par,int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            // if node is not visted then call for this node 
            if(vis[it]==0){
                if(dfs(node,it,vis,adj)){
                    return 1;
                }
            }
            // if you are able to come back to same node then you can graph have cycle
            else if(it!=par){
                return 1;
            }
                
            }
            return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        // what if connected components - multiple graphs you use this pattern 
        for(int i=0;i<V;i++){
            if(vis[i]==0)
            {
                if(dfs(-1,i,vis,adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}