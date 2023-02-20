#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution{
    public:
    vector<int> topo(int V, vector<int> adj[]) {
        // create the ans array and storing the solutions 
        // create the indegree array - for storing the indegree of the node 
        vector<int> ans, in(V, 0);
        queue<int> q;
        for(int i=0;i<V;i++) {
            for(auto x: adj[i]) {
                in[x]++;
            }
        }
        for(int i=0;i<V;i++) if(in[i]==0) q.push(i);
        while(q.size()) {
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(auto x: adj[node]) {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
        return ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        string a, b, ans="";
        
        vector<int> adj[k];
        
        for(int i=0;i<n-1;i++) {
            a=dict[i], b=dict[i+1];
            
            int len = min(a.size(), b.size());
            
            for(int ptr=0;ptr<len; ptr++) {
                if(a[ptr] != b[ptr]) {
                    adj[a[ptr]-'a'].push_back(b[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> topoArray=topo(k, adj);
        for(auto x: topoArray) {
            ans += (x+'a');
        }
        return ans;
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
