class Solution {
  public:
    int factorial(int n){
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }
    int vowelCount(string& s) {
        // code here
        string vowels = "aeiou";
        unordered_map<char, int>mp;
        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) mp[ch]++;
        }
        if(mp.size() == 0) return 0;
        int val = factorial(mp.size());
        
        for(auto it : mp){
            val *= it.second;
        }
        
        return val;
    }
};