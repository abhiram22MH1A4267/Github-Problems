class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<vector<int>> my_set;
    
        pq.push({arr1[0] + arr2[0], 0, 0});
        my_set.insert({0, 0});
    
        int flag = 1;
        for (int count = 0; count < k && flag; count++) {
            vector<int> temp = pq.top();
            pq.pop();
    
            int i = temp[1];
            int j = temp[2];
    
            ans.push_back({arr1[i], arr2[j]});
    
            flag = 0;
            if (i + 1 < arr1.size()) {
                vector<int> temp1 = {i + 1, j};
                if (my_set.find(temp1) == my_set.end()) {
                    pq.push({arr1[i + 1] + arr2[j], i + 1, j});
                    my_set.insert(temp1);
                }
                flag = 1;
            }
    
            if (j + 1 < arr2.size()) {
                vector<int> temp1 = {i, j + 1};
                if (my_set.find(temp1) == my_set.end()) {
                    pq.push({arr1[i] + arr2[j + 1], i, j + 1});
                    my_set.insert(temp1);
                }
                flag = 1;
            }
        }
    
        return ans;
    }
};
