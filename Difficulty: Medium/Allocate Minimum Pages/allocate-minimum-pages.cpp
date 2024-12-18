//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int>arr, int k, int mid){
        int total = 1, sum = 0;
        for(int i : arr){
            sum += i;
            if(sum > mid){
                total++;
                sum = i;
            }
        }
        return total <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        int begin = 0, end = 0;
        for(int i : arr){
            begin = max(begin, i);
            end += i;
        }
        int ans = begin;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(isPossible(arr, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                begin = mid + 1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends