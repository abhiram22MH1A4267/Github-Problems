class Solution {
  public:
    int largeRec(vector<int>&heights){
        heights.push_back(-1);
        stack<pair<int,int>>st;
        int largeArea{};
        for(int i = 0; i < heights.size(); i++){
            int startIdx{i};
            while(!st.empty() and heights[i] < st.top().first){
                auto [height, idx] = st.top();
                st.pop();
                largeArea = max(largeArea, height * (i-idx));
                startIdx = idx;
            }
            st.push({heights[i], startIdx});
        }
        return largeArea;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int rows = mat.size(), col = mat[0].size(), maxRect{};
        for(int r = 1; r < rows; ++r){
            for(int c = 0; c < col; ++c){
                mat[r][c] = mat[r][c] * (mat[r][c] + mat[r-1][c]);
            }
        }
        for(int r = 0; r < rows; ++r){
            maxRect = max(maxRect, largeRec(mat[r]));
        }
        return maxRect;
    }
};