//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        long long dp[sum+1];
        dp[0] = 1;
        for(int i = 1; i <= sum; i++){
            dp[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= sum; j++){
                if(coins[i] <= j){
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        
        return dp[sum];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends