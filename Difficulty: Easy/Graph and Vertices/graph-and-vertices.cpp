//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long power(long long x, long long y){
        long long ans = 1;
        while(y > 0){
            if(y & 1){
                ans = (ans * x);
            }
            x = (x * x);
            y /= 2;
        }
        return ans;
    }
    long long count(int n) {
        // your code here
        long long x = (n * (n-1)) / 2;
        return power(2, x);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends