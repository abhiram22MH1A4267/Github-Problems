class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.length(), val = INT_MIN;
        pair<int, int>p = {0,0};
        
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > i; j--){
                int digit = s[j] - '0';
                if((s[i] - '0') < digit && (val < digit)){
                    val = digit;
                    p = {i, j};
                }
            }
            if(val > 0) {
                swap(s[p.first], s[p.second]);
                break;
            }
        }
        return s;
    }
};