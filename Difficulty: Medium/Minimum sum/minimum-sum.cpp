class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>x,y;
        
        for(int i = 0; i < n; i++){
            x.push_back(arr[i]);
            i++;
            if(i < n){
                y.push_back(arr[i]);
            }
        }
        int x1 = x.size(), y1 = y.size();
        string ans;
        int c = 0, t;
        while(x1 && y1){
            t = x[--x1] + y[--y1] + c;
            ans += to_string(t%10);
            c = t/10;
        }
        while(x1){
            t = x[--x1]+c;
            ans += to_string(t%10);
            c = t/10;
        }
        while(y1){
            t = y[--y1]+c;
            ans += to_string(t%10);
            c = t/10;
        }
        if(c){
            ans += to_string(c);
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0'){
            i++;
        }
        return ans.substr(i);
    }
};