class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int shortest = INT_MAX;

        for (int start = 0; start < V; start++) {
            vector<int> dist(V, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } 
                    else if (dist[v] >= dist[u]) {
                        shortest = min(shortest, dist[v] + dist[u] + 1);
                    }
                }
            }
        }

        return (shortest == INT_MAX) ? -1 : shortest;
    }
};
