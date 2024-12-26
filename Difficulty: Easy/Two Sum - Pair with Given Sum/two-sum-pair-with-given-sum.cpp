//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = pow(10,5);
        vector<int>v(n,0);
        for(int i = 0; i < arr.size(); i++){
            v[arr[i]]++;
        }
        for(int i = 0; i < arr.size(); i++){
            int diff = target - arr[i];
            if(diff >= 0){
                if(diff == arr[i] && v[diff] > 1) return true;
                else if(diff != arr[i] && v[diff] != 0) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends