#include <bits/stdc++.h>
using namespace std;

//User function Template for C++
class Solution{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
    // ------------- by khans algorithim (bfs)
    
	   // - create the adj list 
	   // - set the indegree of the every node
	   // - push into the queue which have indegree 0
	   // - when we will pop the node checkout the who are the adjcecny node redure the indegree of these nodes
	   // by chance anyone have indegree 0, then push into the queue data strutrue 
	    
	   // + remember the point - you have to point the element then store the element into the vector ans result array
	    
	    int N = n;
	    
	   // 1. step - create the adj list
	    vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    
	    int indegree[N] = {0};
	    vector<int> ans;
	    queue<int> q;
	    
	    for(int i = 0; i<N; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0; i<N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            
	             if(indegree[it] == 0) {
	                q.push(it);
	             }
	        }
	    }
	    
	    // if answer array size is equal to give nodes size then you are able to perfom the complete task
	    if(ans.size() == N){
	        return ans;
	    }
	    return {};
	    
    }
};


int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}