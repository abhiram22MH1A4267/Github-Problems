class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>dp(n);
        vector<int>best;
        
        for(int i = 0; i < n; i++){
            vector<int>max;
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    if(dp[j]. size() > max.size() || dp[j].size() == max.size() && dp[j] > max){
                        max = dp[j];
                    }
                }
            }
            
            dp[i] = max;
            dp[i].push_back(arr[i]);
            
            if(dp[i].size() > best.size() || dp[i].size() == best.size() && dp[i] > best){
                best = dp[i];
            }
        }
        return best;
    }
};