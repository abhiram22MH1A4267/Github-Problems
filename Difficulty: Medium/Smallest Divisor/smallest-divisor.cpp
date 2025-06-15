class Solution {
  public:
    bool check(int mid, vector<int>&arr, int k){
        int sum = 0;
        for(int i : arr){
            sum += (i + mid - 1) / mid;
        }
        return sum <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1, high = *max_element(arr.begin(), arr.end()), ans = 0;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(mid, arr, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};
