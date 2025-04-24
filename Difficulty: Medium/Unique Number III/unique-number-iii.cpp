//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void CountFreq(int n, vector<int>&freq){
        if(n < 0){
            freq[31] += 1;
            n = abs(n);
        }
        for(int i = 0; i < 31; i++){
            freq[i] += ((n>>i) & 1);
        }
        // for(int i : freq){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
    }
    int getSingle(vector<int> &arr) {
        // code here
        vector<int>freq(32, 0);
        for(int i : arr){
            CountFreq(i, freq);
        }
        int ans = 0;
        for(int i = 0; i < 31; i++){
            // cout<<i<<" ";
            if((freq[i]%3) != 0){
                ans += pow(2,i);
            }
        }
        if(freq[31] % 3 != 0){
            ans *= -1;
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
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends