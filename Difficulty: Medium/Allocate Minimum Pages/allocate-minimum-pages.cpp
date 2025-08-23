class Solution {
  public:
    bool isPossible(vector<int>arr, int k, int mid){
        int total = 1, sum = 0;
        for(int i : arr){
            sum += i;
            if(sum > mid){
                total++;
                sum = i;
            }
        }
        return total <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        int begin = 0, end = 0;
        for(int i : arr){
            begin = max(begin, i);
            end += i;
        }
        int ans = begin;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(isPossible(arr, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                begin = mid + 1;
            }
        }
        return ans;
    }
};