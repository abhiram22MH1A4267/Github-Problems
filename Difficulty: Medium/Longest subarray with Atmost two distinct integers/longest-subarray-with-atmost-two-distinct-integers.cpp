class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size(), count = 0, i = 0, ans = 0;
        unordered_map<int,int>mp;
        for(int j = 0; j < n; j++){
            mp[arr[j]]++;
            count++;
            while(i < j && mp.size() > 2){
                mp[arr[i]]--;
                count--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                    i++;
                    break;
                }
                i++;
            }
            ans = max(ans, count);
            // cout<<count<<endl;
        }
        return ans;
    }
};