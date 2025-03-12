//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int SetCount(int n){
        int count = 0;
        while(n){
            count += (n&1);
            n >>= 1;
        }
        return count;
    }
    int countBits(int n) {
        // code here
        int val = 1, i = 0;
        while(val < n){
            val <<= 1;
            i++;
        }
        val >>= 1;
        int ans = ((val / 2) * (i-1));
        for(int i = val; i <= n; i++){
            ans += SetCount(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.
#define int long long int

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.countBits(N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends