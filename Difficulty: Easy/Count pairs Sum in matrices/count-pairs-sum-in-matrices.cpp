class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_map<int,int>mp1, mp2;
        for(auto it : mat1){
            for(int i : it){
                mp1[i]++;
            }
        }
        for(auto it : mat2){
            for(int i : it){
                mp2[i]++;
            }
        }
        int count = 0;
        for(auto it : mp1){
            int val = x - it.first;
            if(mp2.find(val) != mp2.end()){
                count++;
            }
        }
        return count;
    }
};