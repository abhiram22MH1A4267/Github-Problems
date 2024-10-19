//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        int needChange = str[n-1] > '5';
        str[n-1] = '0';
        if(needChange){
            for(int i = n-2; i >= 0; i--){
                int digit = (str[i] - '0') + 1;
                if(digit < 10){
                    str[i] = digit + '0';
                    return str;
                }
                str[i] = '0';
            }
            str = '1' + str;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends