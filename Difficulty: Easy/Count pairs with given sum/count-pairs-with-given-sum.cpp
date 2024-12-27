//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i : arr){
            mp[i]++;
        }
        int ans = 0;
        for(int i : arr){
            int m = target - i;
            if(mp.find(m) != mp.end()){
                if(i == m){
                    ans += (1 * (mp[m]-1));
                }
                else{
                    ans += (1 * mp[m]);
                }
            }
        }
        if((ans&1) == 0) return ans/2;
        return (ans/2)+1;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends