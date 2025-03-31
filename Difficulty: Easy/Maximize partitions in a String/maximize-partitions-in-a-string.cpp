//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char,int>mp, part;
        for(char ch : s){
            mp[ch]++;
        }
        int ans = 0;
        for(char ch : s){
            part[ch]++;
            int flag = 0;
            for(auto it : part){
                if(it.second != mp[it.first]){
                    flag = 1;
                    break;
                }
            }
            if(flag != 1){
                ans++;
                part = {};
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends