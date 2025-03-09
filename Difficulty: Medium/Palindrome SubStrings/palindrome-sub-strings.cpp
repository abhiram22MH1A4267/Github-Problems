//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void subString(string& s, int left, int right, int &ans){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
            if((right - left-1) > 1) ans++;
        }
    }
    int countPS(string &s) {
        // code here
        int ans = 0, n = s.length();
        for(int i = 0; i < n; i++){
            subString(s, i, i, ans);
            subString(s, i, i+1, ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends