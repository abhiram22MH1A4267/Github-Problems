//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> solve(int n, vector<int>&ans, int i){
        if(i >= n) return ans;
        vector<int>arr(i+1, 0);
        arr[0] = arr[i] = 1;
        for(int j = 1; j < i; j++){
            arr[j] = ans[j-1] + ans[j];
        }
        vector<int>res = solve(n, arr, i+1);
        return res;
    }
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n == 1) return {1};
        vector<int>ans = {1,1};
        vector<int>res = solve(n, ans, 2);
        return res;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends