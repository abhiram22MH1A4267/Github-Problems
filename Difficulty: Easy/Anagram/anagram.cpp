//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n = s1.length(), m = s2.length();
        if(n != m) return 0;
        unordered_map<char,int>mp1, mp2;
        for(int i = 0; i < n; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(auto it : mp1){
            if(mp2[it.first] != it.second) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends