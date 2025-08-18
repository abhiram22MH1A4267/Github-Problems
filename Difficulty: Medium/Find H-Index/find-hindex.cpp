class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int>arr(n+1, 0);
        for(int i : citations){
            arr[min(i,n)]++;
        }
        
        int count = 0;
        for(int i = n; i >= 0; i--){
            count += arr[i];
            if(count >= i) return i;
        }
        
        return 0;
    }
};