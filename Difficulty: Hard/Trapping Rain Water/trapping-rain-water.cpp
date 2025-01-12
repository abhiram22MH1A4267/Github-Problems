//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        vector<int>lt, rt;
        int max = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            if(max <= arr[i]) max = arr[i];
            lt.push_back(max);
        }
        max = 0;
        for(int i = n-1; i >= 0; i--){
            if(max < arr[i]) max = arr[i];
            rt.push_back(max);
        }
        reverse(rt.begin(), rt.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(lt[i] < rt[i]){
                ans += abs(lt[i] - arr[i]);
            }
            else{
                ans += abs(rt[i] - arr[i]);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends