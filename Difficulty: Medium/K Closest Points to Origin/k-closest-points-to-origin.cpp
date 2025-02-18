//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        map<int,vector<int>>mp;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int val = pow(points[i][0], 2) + pow(points[i][1], 2);
            mp[val].push_back(i);
        }
        vector<vector<int>>ans;
        int flag = 0;
        for(auto it : mp){
            for(int i : it.second){
                if(ans.size() == k){
                    flag = 1;
                    break;
                }
                ans.push_back(points[i]);
            }
            if(flag == 1) break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends