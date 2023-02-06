
#include <bits/stdc++.h>
using namespace std;


// NOTE - if you are able to come back to same node then you can graph have cycle


class Solution {
    private:
    // BFS Algortim used here- 
    bool cyclePresent(int node, vector<int> adj[], int vis[]){
        
        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node] = 1;
        
        while(!q.empty()){
            int currNode = q.front().first;
            int parNode = q.front().second;
            
            q.pop();
            
            for(auto x: adj[currNode]){
                if(!vis[x]){
                    q.push({x,currNode});
                    vis[x] = 1;
                }else if(parNode != x){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(cyclePresent(i,adj, vis) == true){
                    return true;
                }
            }
        }
        return false;
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