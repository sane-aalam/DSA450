#include<bits/stdc++.h>
using namespace std;

/* algorithm ( simple read this notes )
- in order to perform
- create queue data structure
- need a distance array 
- i know - we can use set data stcutre and priority queue
           learning i'm using queue data sturcture 
- mathmatically equations ):
  dis[it] > dis[node] + wieght 
  dis[it] = dis[node] + wieght
  
  
Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).
  
 */
  
class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> Distance(V);
        
        for(int i = 0; i<V; i++){
            Distance[i] = INT_MAX;
        }
        
        queue<int> q;
        q.push(S);
        // khud se zero distance hoti hay obevesoully
        Distance[S] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                int adjnode = it[0];
                int weight = it[1];
                
                // case2 - MATH Equations apply
                if(Distance[adjnode] > Distance[node] + weight){
                    Distance[adjnode] = Distance[node] + weight;
                    q.push(adjnode);
                }
            }
        }
        return Distance;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
