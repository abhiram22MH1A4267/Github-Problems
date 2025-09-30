class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        int total = 1 << n;
        vector<string> res;
        res.reserve(total);

        for (int i = 0; i < total; i++) {
            bitset<32> b(i);
            string s = b.to_string();
            res.push_back(s.substr(32 - n));
        }

        return res;
    }
};