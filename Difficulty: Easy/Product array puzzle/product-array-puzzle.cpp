//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long pro = 1;
        int zero = 0, n = arr.size();
        for(int i : arr){
            if(i == 0) zero++;
            else pro *= i;
        }
        vector<int>ans(n,0);
        if(zero > 1) return ans;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                ans[i] = pro;
            }
            else{
                if(zero == 1){
                    ans[i] = 0;
                }
                else{
                    ans[i] = (pro/arr[i]);
                }
            }
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends