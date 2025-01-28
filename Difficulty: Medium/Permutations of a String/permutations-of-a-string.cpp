//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void Traverse(int p, string curr, vector<bool>&vis, set<string>&ans, int n, string &s){
        if(p == n){
            ans.insert(curr);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = 1;
                curr += s[i];
                Traverse(p+1, curr, vis, ans, n, s);
                curr.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        int n = s.length();
        vector<bool> vis(n,0);
        
        Traverse(0, "", vis, ans, n, s);
        
        vector<string>ans1;
        for(auto it : ans){
            ans1.push_back(it);
        }
        return ans1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends