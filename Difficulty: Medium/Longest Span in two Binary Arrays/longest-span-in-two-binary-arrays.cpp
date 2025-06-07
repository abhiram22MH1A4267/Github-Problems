class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        int sum1 = 0, sum2 = 0, res = 0;
        unordered_map<int,int>mp;
        
        for(int i = 0; i < n; i++){
            sum1 += a1[i];
            sum2 += a2[i];
            
            int diff = sum1 - sum2;
            
            if(diff == 0) res = max(res, i+1);
            
            else if(mp.count(diff)) res = max(res, i - mp[diff]);
            
            else mp[diff] = i;
        }
        
        return res;
    }
};