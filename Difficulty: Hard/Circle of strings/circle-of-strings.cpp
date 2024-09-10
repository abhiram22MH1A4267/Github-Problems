//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>&graph, vector<int>&visited){
        visited[node] = 1;
        for(int adj : graph[node]){
            if(!visited[adj]){
                dfs(adj,graph,visited);
            }
        }
        return true;
    }
    bool isconnected(vector<vector<int>>&graph, int start){
        vector<int>visited(26,0);
        dfs(start,graph,visited);
        for(int i = 0; i < 26; i++){
            if(graph[i].size() > 0 && !visited[i]){
                return false;
            }
        }
        return true;
    }
    int isCircle(vector<string> &arr) {
        // code here
        vector<int>inDegree(26,0),outDegree(26,0);
        vector<vector<int>>graph(26);
        for(string &s : arr){
            int first = s.front() - 'a';
            int last = s.back() - 'a';
            outDegree[first]++;
            inDegree[last]++;
            graph[first].push_back(last);
        }
        for(int i = 0; i < 26; i++){
            if(inDegree[i] != outDegree[i]){
                return 0;
            }
        }
        int start = arr[0].front() - 'a';
        return isconnected(graph,start) ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends