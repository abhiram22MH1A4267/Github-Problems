//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int ans = 0;
        int j = 0, n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i] >= prices[j]){
                ans = max(ans, prices[i-1] - prices[j]);
                continue;
            }
            else{
                ans = max(ans, prices[i-1] - prices[j]);
                j = i;
            }
        }
        ans = max(ans, prices[n-1] - prices[j]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends