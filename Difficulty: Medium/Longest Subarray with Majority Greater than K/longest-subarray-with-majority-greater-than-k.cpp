//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> first_occurrence;
        int prefix_sum = 0;
        int max_len = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > k) prefix_sum += 1;
            else prefix_sum -= 1;

            if (prefix_sum > 0) {
                max_len = i + 1;
            } else {
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends