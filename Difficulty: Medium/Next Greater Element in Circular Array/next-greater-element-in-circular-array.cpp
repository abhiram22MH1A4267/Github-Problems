//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n, INT_MIN), vec;
        stack<int>st;
        
        for(int i = n-1; i >= 0; i--){
            if(arr[n-1] < arr[i]){
                ans[n-1] = arr[i];
            }
            
            if(st.empty()) st.push(arr[i]);
            
            else if(st.top() > arr[i]){
                ans[i] = st.top();
                vec.push_back(st.top());
            }
            
            else {
                for(int j = vec.size()-1; j >= 0; j--){
                    if(vec[j] > arr[i]){
                        ans[i] = vec[j];
                        break;
                    }
                }
            }
            
            st.push(arr[i]);
        }
        int maxi = *max_element(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            if(arr[i] == maxi){
                ans[i] = -1;
                continue;
            }
            if(ans[i] == INT_MIN) {
                for(int j = 0; j < i; j++){
                    if(arr[i] < arr[j]){
                        ans[i] = arr[j];
                        break;
                    }
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
        Solution ob;
        int n = arr.size();
        vector<int> v = ob.nextLargerElement(arr);
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends