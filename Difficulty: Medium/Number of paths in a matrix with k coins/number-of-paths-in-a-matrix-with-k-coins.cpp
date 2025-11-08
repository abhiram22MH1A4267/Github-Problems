class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size(), m = mat[0].size();
    
        vector<vector<int>> prev(m, vector<int>(k + 1, 0));
        vector<vector<int>> curr(m, vector<int>(k + 1, 0));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sum = 0; sum <= k; sum++) {
                    
                    if (i == 0 && j == 0) {
                        
                        curr[j][sum] = (sum == mat[0][0]);
                        continue;
                    }
    
                    curr[j][sum] = 0;
    
                    if (sum - mat[i][j] >= 0) {
                        
                        if (i > 0) curr[j][sum] += prev[j][sum - mat[i][j]];
                       
                        if (j > 0) curr[j][sum] += curr[j - 1][sum - mat[i][j]];
                    }
                }
            }
            prev = curr;
        }
    
        return prev[m - 1][k];
    }
};