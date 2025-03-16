//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int currIndex = 0, max_index = 0, jumps = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            max_index = max(max_index, arr[i] + i);
            
            if(i == currIndex){
                currIndex = max_index;
                jumps++;
                if(currIndex >= n-1){
                    return jumps;
                }
            }
        }
        
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends