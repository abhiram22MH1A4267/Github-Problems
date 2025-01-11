//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int>v(26,0);
        int ans = 0;
        int l = 0, r = 0;
        while(r < s.length()){
            while(v[s[r] - 'a'] == 1){
                v[s[l] - 'a'] = 0;
                l++;
            }
            v[s[r] - 'a'] = 1;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends