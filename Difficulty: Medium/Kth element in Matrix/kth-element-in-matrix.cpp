class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int max_ele = INT_MIN;
        vector<int>vec(10001, 0);
        for(auto it : matrix){
            for(int i : it){
                vec[i]++;
                max_ele = max(max_ele, i);
            }
        }
        for(int i = 1; i <= 10001; i++){
            k -= vec[i];
            if(k <= 0) return i;
        }
        return max_ele;
    }
};