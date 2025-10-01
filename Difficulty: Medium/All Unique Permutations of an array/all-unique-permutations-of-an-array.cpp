class Solution {
  public:
    void backtrack(vector<int>& arr, vector<bool>& visited, vector<int>& curr,  vector<vector<int>>& result) {

        if (curr.size() == arr.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
        
            if (visited[i]) continue;
            
            if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            curr.push_back(arr[i]);
            
            backtrack(arr, visited, curr, result);
            
            curr.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(arr.size(), false);

        backtrack(arr, visited, curr, result);
    
        return result;
    }
};