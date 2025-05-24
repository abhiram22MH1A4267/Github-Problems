class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n = s.length();
        long long result = 0, curr = 0;
        int mod = 1000000007;

        for (int i = 0; i < n; ++i) {
            int num = s[i] - '0';
            curr = curr * 10 + num * (i + 1);
            result += curr;
        }

        return static_cast<int>(result);
        
    }
};