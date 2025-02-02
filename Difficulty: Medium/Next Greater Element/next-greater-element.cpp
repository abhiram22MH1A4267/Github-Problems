//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int>st;
        for(int i : arr){
            st.push(i);
        }
        int next_greater = arr[n-1];
        st.pop();
        vector<int>ans(n,-1), greater;
        int i = 1;
        while(!st.empty()){
            int val = st.top();
            st.pop();
            if(val < next_greater){
                ans[i] = next_greater;
            }
            if(!st.empty() && st.top() < val){
                greater.push_back(next_greater);
                next_greater = val;
            }
            if(val >= next_greater){
                for(int j = greater.size()-1; j >= 0 ; j--){
                    if(val < greater[j]){
                        ans[i] = greater[j];
                        break;
                    }
                }
            }
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends