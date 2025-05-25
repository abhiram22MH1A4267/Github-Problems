class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size(), max_ele = 0;
        for(int i = 0; i < n; i++){
            max_ele = max(max_ele, arr[i]);
        }
        
        vector<bool>vis(max_ele+1, false);
        for(int i = 0; i < n; i++){
            vis[arr[i]] = true;
        }
        for(int a = 1; a <= max_ele; a++){
            if(!vis[a]) continue;
            for(int b = 1; b <= max_ele; b++){
                if(!vis[b]) continue;
                int c = sqrt(a * a + b * b);
                
                if(c * c != a * a + b * b || c > max_ele) continue;
                
                if(vis[c]) return true;
            }
        }
        return false;
    }
};