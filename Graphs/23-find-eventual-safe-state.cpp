#include <bits/stdc++.h>
using namespace std;

// User function Template for C++


// Approach

// In this question we have to find nodes with outdegree=0
// so we will reverse the direction of edges 
// and we will apply topological sort and 
// find Queue having indegree=0

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ReverseAdj[V];
        vector<int> indegree(V,0);
        
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                ReverseAdj[it].push_back(i);
                // we are creating the adjecny list - reverse order 
                // i -> it - not reverse order 
                // it -> i - reverse order 
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    
        vector<int> arr; // safe nodes
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            arr.push_back(node);
            for(auto it : ReverseAdj[node]){
                indegree[it] --;
                // recuding the indegree of the nodes 
                if(indegree[it] == 0){
                    q.push(it);
                }
            } 
        }
        sort(arr.begin(), arr.end());
        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}
