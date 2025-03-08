//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string subString(string &s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string &s) {
        // code here
        string ans = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            string s1 = subString(s,i,i);
            if(s1.length() > ans.length()){
                ans = s1;
            }
            string s2 = subString(s,i,i+1);
            if(s2.length() > ans.length()){
                ans = s2;
            }
        }
        return ans;
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends