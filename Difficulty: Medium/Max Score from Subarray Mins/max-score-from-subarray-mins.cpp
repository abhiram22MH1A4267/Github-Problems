class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans = INT_MIN, n = arr.size();
        for(int i = 1; i < n; i++){
            ans = max(ans, arr[i-1] + arr[i]);
        }
        return ans;
    }
};