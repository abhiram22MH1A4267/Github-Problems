class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int ans = 0, sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int i : arr){
            sum += i;
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};