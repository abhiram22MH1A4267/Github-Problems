//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(char ch : s){
            if(st.empty()){
                if(ch == ']' || ch == '}' || ch == ')') return false;
                else{
                    st.push(ch);
                }
            }
            else{
                if((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']')){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends