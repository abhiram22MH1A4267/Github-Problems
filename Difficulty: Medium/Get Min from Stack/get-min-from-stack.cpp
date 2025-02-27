//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>vec, mini;
    int n = 0;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        vec.push_back(x);
        if(n == 0){
            mini.push_back(x);
        }
        else{
            mini.push_back(min(mini[n-1], x));
        }
        n++;
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(n > 0){
            vec.pop_back();
            mini.pop_back();
            n--;
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(n > 0) return vec[n-1];
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(n <= 0) return -1;
        return mini[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends