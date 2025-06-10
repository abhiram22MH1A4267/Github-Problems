class Solution {
  public:
    int countStrings(string &s) {
        // code here
        unordered_map<char, int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        int ans = 0, n = s.length();
        bool flag = false;
        for(char ch : s){
            if(mp[ch] > 1) flag = true;
            ans += n - mp[ch];
        }
        ans /= 2;
        ans += flag ? 1 : 0;
        return ans;
    }
};
