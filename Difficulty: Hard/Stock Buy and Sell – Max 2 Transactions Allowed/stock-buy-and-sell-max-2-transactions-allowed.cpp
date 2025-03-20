//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        
        
        vector<int>leftProfit(n,0), rightProfit(n,0);
        
        int minPrice = prices[0];
        
        for(int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice);
        }
        
        int maxPrice = prices[n-1];
        
        for(int i = n-2; i >= 0; i--){
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]);
        }
        
        int maxProfit = rightProfit[0];
        for(int i = 1; i < n; i++){
            maxProfit = max(maxProfit, leftProfit[i-1] + rightProfit[i]);
        }
        
        return maxProfit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends