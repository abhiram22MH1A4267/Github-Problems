//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        stack<char>st1, st2;
        for(int i = 0; i < s1.length(); i++){
            st1.push(s1[i]);
        }
        for(int i = 0; i < s2.length(); i++){
            st2.push(s2[i]);
        }
        string ans;
        int extra = 0;
        while(!st1.empty() && !st2.empty()){
            int sum = (st1.top() - '0') + (st2.top() - '0') + extra;
            if((sum & 1) == 0){
                ans += '0';
                extra = sum == 0 ? 0 : 1;
            }
            else{
                ans += '1';
                extra = sum == 1 ? 0 : 1;
            }
            st1.pop();
            st2.pop();
        }
        while(!st1.empty()){
            if(extra == 1){
                if(st1.top() == '1'){
                    ans += '0';
                }
                else{
                    ans += '1';
                    extra = 0;
                }
            }
            else{
                ans += st1.top();
            }
            st1.pop();
        }
        while(!st2.empty()){
            if(extra == 1){
                if(st2.top() == '1'){
                    ans += '0';
                }
                else{
                    ans += '1';
                    extra = 0;
                }
            }
            else{
                ans += st2.top();
            }
            st2.pop();
        }
        if(extra == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(ans[i] != '1'){
            i++;
        }
        ans = ans.substr(i);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends