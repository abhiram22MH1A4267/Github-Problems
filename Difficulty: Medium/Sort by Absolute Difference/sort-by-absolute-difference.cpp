class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        map<int,vector<int>>mp;
        
        for(int i : arr){
            mp[abs(x - i)].push_back(i);
        }
        
        vector<int>ans;
        
        for(auto it : mp){
            
            for(int i : it.second){
                ans.push_back(i);
            }
        }
        
        arr = ans;
    }
};