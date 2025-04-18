//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Trie {
  public:
    vector<string>arr;
    Trie() {
        // implement Trie
    }

    void insert(string &word) {
        // insert word into Trie
        arr.push_back(word);
    }

    bool search(string &word) {
        // search word in the Trie
        if(find(arr.begin(), arr.end(), word) != arr.end()) return true;
        return false;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        int n = word.size();
        for(int i = 0; i < arr.size(); i++){
            string sub = arr[i].substr(0,n);
            if(word == sub) return true;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends