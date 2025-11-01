class Solution {
  public:
    
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& stack) {
    
        visited[node] = 1; 
    
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) {
                
                return false; 
            } else if (visited[neighbor] == 0) {
                if (!dfs(neighbor, adj, visited, stack)) {
                    
                    return false; 
                }
            }
        }
        visited[node] = 2; 
        stack.push_back(node);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        for (auto& pre : prerequisites) {
            int dest = pre[0];
            int src = pre[1];
            adj[src].push_back(dest);
        }
        vector<int> visited(n, 0);
        vector<int> stack;
    
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, stack)) {
                    
                    return {}; 
                }
            }
        }
        reverse(stack.begin(), stack.end()); 
        return stack;
    }
};