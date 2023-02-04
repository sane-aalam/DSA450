/* Breadth First Traversal -
 Given a directed graph.The task is to do Breadth First Traversal of this graph starting from 0. Note : 
 One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of 
 the graph starting from the 0th vertex, from left to right according to the graph. Also, 
 you should only take nodes directly or indirectly connected from Node 0 in consideration
 */

// TC = o(n) + o(2E)
// SC = o(n)

#include <bits/stdc++.h>
using namespace std;

// start code here 
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // create visted array and queue data structure for perform BFS algo
        int vist[V] = {0};
        vist[0] = 1; 
        queue<int>q;
        q.push(0);
        
        // create answer array for storing the answer
        vector<int> result;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            result.push_back(node);
            
            for(auto x : adj[node]){
                if(!vist[x]){
                    vist[x] = 1;
                    q.push(x);
                }
            }
        }
        return result;
    }
};

// main function 
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        // create adj list for storing the nieghbours nodes
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
