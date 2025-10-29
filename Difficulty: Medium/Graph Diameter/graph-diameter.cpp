class Solution {
  public:
  
    struct FarthestResult {
        int node;
        int distance;
    };
    
    FarthestResult bfs(int start_node, int n, const vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
    
        q.push({start_node, 0});
        visited[start_node] = true;
    
        int farthest_node = start_node;
        int max_dist = 0;
    
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
    
            int u = current.first;
            int dist = current.second;
    
            if (dist > max_dist) {
                max_dist = dist;
                farthest_node = u;
            }
    
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, dist + 1});
                }
            }
        }
        return {farthest_node, max_dist};
    }

    int diameter(int n, vector<vector<int>>& edges) {
        // Code here
        if (n == 0) return 0;
    
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        if (n == 1) return 0;
    
        int arbitrary_start_node = 1;
        FarthestResult result1 = bfs(arbitrary_start_node, n, adj);
        
        FarthestResult result2 = bfs(result1.node, n, adj);
        
        return result2.distance;
    }
};
