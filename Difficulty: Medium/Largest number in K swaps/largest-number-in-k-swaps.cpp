//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    void findMaxUtil(string s, int k, string &maxStr, int index) {
        if (k == 0)
            return;

        int n = s.length();
        char maxChar = s[index];

        for (int i = index + 1; i < n; i++) {
            if (s[i] > maxChar)
                maxChar = s[i];
        }

        
        if (maxChar != s[index])
            k--;

        for (int i = n - 1; i >= index; i--) {
            if (s[i] == maxChar) {
                swap(s[i], s[index]);

                if (s.compare(maxStr) > 0)
                    maxStr = s;

                findMaxUtil(s, k, maxStr, index + 1);
                
                
                swap(s[i], s[index]);
            }
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string maxStr = s;
        findMaxUtil(s, k, maxStr, 0);
        return maxStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends