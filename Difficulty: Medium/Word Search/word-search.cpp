//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n ,m;
    bool check(vector<vector<char>>&mat, vector<vector<int>>&vis, string& word, int index, int i, int j){
        if(index == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[index] || vis[i][j]){
            return false;
        }
        vis[i][j] = 1;
        if(check(mat, vis, word, index+1, i-1, j) || 
            check(mat, vis, word, index+1, i+1, j) ||
            check(mat, vis, word, index+1, i, j-1) ||
            check(mat, vis, word, index+1, i, j+1)) return true;
        vis[i][j] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        n = mat.size(), m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]) {
                    if(check(mat, vis, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends