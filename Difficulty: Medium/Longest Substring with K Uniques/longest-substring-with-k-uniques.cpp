class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size(), count = 0, i = 0, ans = -1;
        unordered_map<char,int>mp;
        for(int j = 0; j < n; j++){
            mp[s[j]]++;
            count++;
            while(i < j && mp.size() > k){
                mp[s[i]]--;
                count--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                    i++;
                    break;
                }
                i++;
            }
            if(mp.size() == k) ans = max(ans, count);
            // cout<<count<<endl;
        }
        return ans;
    }
};