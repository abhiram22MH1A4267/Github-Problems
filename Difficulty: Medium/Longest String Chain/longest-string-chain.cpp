//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        map<string, int>mp;
        int ans = 0;
        for(string &str : words){
            int val = 0;
            for(int i = 0; i < str.size(); i++){
                string temp = str.substr(0,i);
                temp += str.substr(i+1);
                if(mp.find(temp) != mp.end()){
                    val = max(val, mp[temp]);
                }
                
            }
            mp[str] = val+1;
            ans = max(ans, mp[str]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends