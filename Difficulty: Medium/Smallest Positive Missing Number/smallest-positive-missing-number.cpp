//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = *max_element(arr.begin(), arr.end());
        if(n <= 0) return 1;
        vector<int>ans(n+1, 0);
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > 0){
                ans[arr[i]]++;
            }
        }
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] == 0) return i;
        }
        return n+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends