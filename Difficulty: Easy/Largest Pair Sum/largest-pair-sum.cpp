//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int first = arr[1] > arr[0] ? arr[1] : arr[0];
        int second = (first == arr[1]) ? arr[0] : arr[1];
        for(int i = 2; i < arr.size(); i++){
            if(arr[i] > first){
                second = first;
                first = arr[i];
            }
            else if(arr[i] > second) second = arr[i];
        }
        return first + second;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends