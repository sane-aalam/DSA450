#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	   // - create the adj list 
	   // - set the indegree of the every node
	   // - push into the queue which have indegree 0
	   // - when we will pop the node checkout the who are the adjcecny node redure the indegree of these nodes
	   // by chance anyone have indegree 0, then push into the queue data strutrue 
	    
	   // + remember the point - you have to point the element then store the element into the vector ans result array
	    vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
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
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            
	             if(indegree[it] == 0)
	             {
	                q.push(it);
	             }
	        }
	    }
	    
	    // if answer array size is equal to give nodes size then you are able to perfom the complete task
	    if(ans.size() == N){
	        return true;
	    }
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}