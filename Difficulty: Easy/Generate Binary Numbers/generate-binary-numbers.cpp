class Solution {
  public:
    string getBinary(int n){
        string val = "";
        while(n > 0){
            val = to_string(n & 1) + val;
            n >>= 1;
        }
        
        // reverse(val.begin(), val.end());
        return val;
    }
    vector<string> generateBinary(int n) {
        // code here
        vector<string>res;
        for(int i = 1; i <= n; i++){
            string binary = getBinary(i);
            res.push_back(binary);
        }
        
        return res;
    }
};