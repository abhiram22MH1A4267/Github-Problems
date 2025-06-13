class Solution {
  public:
    bool finish(vector<int>&arr, int mid, int k){
        int hours = 0;
        for(int i = 0; i < arr.size(); i++){
            hours += arr[i] / mid;
            if(arr[i] % mid != 0){
                hours++;
            }
        }
        return hours <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1, high = *max_element(arr.begin(), arr.end()), res = 0;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(finish(arr, mid, k)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};