class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = 1e6;
        int median = ((mat.size() * mat[0].size()) / 2);
        map<int,int>mp;
        for(auto it : mat){
            for(int i : it){
                mp[i]++;
            }
        }
        
        for(auto it : mp){
            median -= it.second;
            if(median < 0) return it.first;
        }
        
        return 0;
    }
};
