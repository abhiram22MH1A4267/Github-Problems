//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>stalls, int mid, int k){
        int countCow = 1, lastStall = stalls[0];
        for(int i = 0; i < stalls.size(); i++){
            if(stalls[i] - lastStall >= mid){
                countCow++;
                if(countCow == k) return true;
                lastStall = stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int l = 0, h = *max_element(stalls.begin(), stalls.end());
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(isPossible(stalls,mid,k)){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends