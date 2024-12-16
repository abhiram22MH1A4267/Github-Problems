//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        vector<int>arr;
        while(k--){
            if(i < n1 && j < n2 && a[i] < b[j]){
                arr.push_back(a[i]);
                i++;
            }
            else if(i < n1 && j < n2 && b[j] <= a[i]){
                arr.push_back(b[j]);
                j++;
            }
            else if(i < n1 && j >= n2){
                arr.push_back(a[i]);
                i++;
            }
            else if(i >= n1 && j < n2){
                arr.push_back(b[j]);
                j++;
            }
        }
        return arr.back();
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends