class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int low = 0, high = m*n;
        while(low < high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i = 1; i <= m; i++){
                if(n < (mid/i)){
                    count += n;
                }
                else{
                    count += (mid/i);
                }
            }
            if(count >= k){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
