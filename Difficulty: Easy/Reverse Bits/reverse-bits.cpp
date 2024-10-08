//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string printBinary(long long x){
        string ans = "";
        for(int i = 31; i >= 0; i--){
            long long mask = (1 << i);
            if(x & mask) ans += '1';
            else ans += '0';
        }
        return ans;
    }
    long long reversedBits(long long x) {
        // code here
        string ans = printBinary(x);
        // reverse(ans.begin(), ans.end());
        // return stoll(ans, 0, 2);
        long long ans1 = 0;
        for(int i = 0; i < 32; i++){
            if(ans[i] == '1'){
                ans1 += pow(2, i);
            }
        }
        return ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends