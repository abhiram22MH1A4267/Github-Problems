//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>positive,negitive,ans;
        for(int i : arr){
            if(i >= 0) positive.push_back(i);
            else negitive.push_back(i);
        }
        int min_length = min(positive.size(), negitive.size());
        for(int i = 0; i < min_length; i++){
            ans.push_back(positive[i]);
            ans.push_back(negitive[i]);
        }
        if(min_length == positive.size()){
            for(int i = min_length; i < negitive.size(); i++){
                ans.push_back(negitive[i]);
            }
        }
        else{
            for(int i = min_length; i < positive.size(); i++){
                ans.push_back(positive[i]);
            }
        }
        arr = ans;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends