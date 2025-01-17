//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isDetect(int src, vector<vector<int>>&adj, int vis[], int parent){
        vis[src] = 1;
        for(auto it : adj[src]){
            if(!vis[it]){
                if(isDetect(it, adj, vis, src)) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> adj) {
        // Code here
        int n = adj.size();
        int vis[n] = {0};
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(isDetect(i, adj, vis, -1)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends