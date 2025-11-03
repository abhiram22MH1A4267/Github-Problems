class Solution:
    def safeNodes(self, V, edges):
        # Code here
        
        adj = [[] for _ in range(V)]
        
        for u, v in edges:
            adj[u].append(v)
            
        safe = {}
        
        def dfs(i):
            if i in safe:
                return safe[i]
                
            safe[i] = False
            
            for neighbour in adj[i]:
                if not dfs(neighbour):
                    return False
            
            safe[i] = True
            return safe[i]
            
        ans = []
        
        for i in range(V):
            if(dfs(i)):
                ans.append(i)
        return ans
