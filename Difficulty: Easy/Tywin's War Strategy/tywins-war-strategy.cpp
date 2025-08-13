class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), count = 0, ans = 0;
        int total = (n & 1) == 0 ? (n / 2) : (n / 2) + 1;
        vector<int>notmatched;
        
        for(int i = 0; i < n; i++){
            if((arr[i] % k) == 0) count++;
            else notmatched.push_back(arr[i] % k);
        }
        
        if(count >= total) return 0;
        
        sort(notmatched.begin(), notmatched.end());
        
        n = notmatched.size();
        for(int i = n-1; i >= 0; i--){
            ans += (k - notmatched[i]);
            count++;
            if(count >= total) return ans;
        }
        
        return ans;
    }
};