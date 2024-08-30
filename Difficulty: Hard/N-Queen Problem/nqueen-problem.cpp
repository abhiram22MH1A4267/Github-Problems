//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    vector<int>col;
    
    bool check(int row, int i){
        for(int j = 0; j < row; j++){
            if(col[j] == i) return 0;
            if(abs(j-row) == abs(col[j]-i)) return 0;
        }
        return 1;
    }
    void rec(int row, int n){
        if(row == n){
            ans.push_back(col);
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(row,i)){
                col[row] = i;
                rec(row+1, n);
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        col.clear();
        ans.clear();
        col.resize(n);
        rec(0,n);
        for(auto &x : ans){
            for(auto &i : x) i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends