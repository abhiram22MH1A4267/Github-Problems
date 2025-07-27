class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>>v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }
        for(auto it : v){
            for(int j = 0; j < m; j++){
                mat[it.first][j] = 0;
            }
            for(int i = 0; i < n; i++){
                mat[i][it.second] = 0;
            }
        }
    }
};