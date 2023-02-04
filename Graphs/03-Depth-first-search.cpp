#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node,int vist[], vector<int> adj[],vector<int>&result){
        
        // mark visted and push into the result array
        vist[node] = 1;
        result.push_back(node);
        
        // traversal code - WRTN
        for(auto x : adj[node]){
            if(!vist[x]){
                dfs(x,vist,adj, result); // call for next code resursively ):
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // start code 
       int vist[V] = {0};
       vector<int> result;
       int start = 0; // starting node 0
       dfs(start,vist,adj,result);
       return result;
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } 
    return 0;
}