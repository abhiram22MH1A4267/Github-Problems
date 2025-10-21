class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        
        for(int i : arr){
            mp[i]++;
        }
        
        map<int,vector<int>>mp1;
        
        for(auto it : mp){
            mp1[it.second].push_back(it.first);
        }
        
        vector<int>res;
        for(auto it : mp1){
            
            if(it.second.size() > 1) sort(it.second.begin(), it.second.end());
            for(auto i : it.second){
                res.push_back(i);
            }
            // cout<<res.back()<<endl;
        }
        
        vector<int>ans;
        
        for(int i = res.size()-1; i >= 0 && ans.size() < k; i--){
            ans.push_back(res[i]);
        }
        
        return ans;
    }
};
