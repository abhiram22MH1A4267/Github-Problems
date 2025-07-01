class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.length(), count = 0;
        map<char, int>mp;
        for(int i = 0; i < k; i++){
            mp[s[i]]++;
        }
        if(mp.size() == k-1) count++;
        int i = 0;
        for(int j = k; j < n; j++){
            mp[s[j]]++;
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            if(mp.size() == k-1) count++;
            i++;
        }
        return count;
    }
};