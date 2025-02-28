//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int eval(int n, int m, string oper){
        if(oper == "+"){
            return (n+m);
        }
        else if(oper == "-"){
            return (m-n);
        }
        else if(oper == "*"){
            return (n*m);
        }
        else{
            return (m/n);
        }
    }
    int evaluate(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<long long>st;
        for(int i = 0; i < n; i++){
            if(arr[i] != "+" && arr[i] != "-" && arr[i] != "*" && arr[i] != "/"){
                int m = stoll(arr[i]);
                st.push(m);
            }
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = eval(a, b, arr[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends