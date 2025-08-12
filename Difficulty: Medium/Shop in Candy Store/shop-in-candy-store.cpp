class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size(), mini = 0, maxi = 0;
        
        sort(prices.begin(), prices.end());
        
        int count = n;
        
        for(int i = 0; i < n && count > 0; i++){
            mini += prices[i];
            count -= (k + 1);
        }
        
        count = n;
        
        for(int i = n-1; i >= 0 && count > 0; i--){
            maxi += prices[i];
            count -= (k + 1);
        }
        
        return {mini, maxi};
    }
};