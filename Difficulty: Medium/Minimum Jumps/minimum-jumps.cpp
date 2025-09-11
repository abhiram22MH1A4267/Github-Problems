class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int currIndex = 0, max_index = 0, jumps = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            max_index = max(max_index, arr[i] + i);
            
            if(i == currIndex){
                currIndex = max_index;
                jumps++;
                if(currIndex >= n-1){
                    return jumps;
                }
            }
        }
        
        return -1;
    }
};
