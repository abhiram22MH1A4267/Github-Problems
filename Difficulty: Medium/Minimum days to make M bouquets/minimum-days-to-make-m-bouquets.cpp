class Solution {
  public:
    int fun(int mid, vector<int>&bloomDay, int k){
        int cnt = 0;
        int n = bloomDay.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            if(mid >= bloomDay[i]){
                cnt++;
                if(cnt == k){
                    total++;
                    cnt = 0;
                }
            }
            else{
                cnt = 0;
            }
        }
        return total;
    }
    int minDaysBloom(vector<int>& bloomDay, int k, int m) {
        // Code here
        int n = bloomDay.size();
        if(m > n/k){
            return -1;
        }
        int i = 1, j = INT_MIN;
        for(int k = 0; k < bloomDay.size(); k++){
            j = max(j,bloomDay[k]);
        }
            int mid;
            int ans = INT_MAX;
            while(i <= j){
                mid = i +(j-i)/2;
                if(fun(mid,bloomDay,k) >= m){
                    ans = min(ans,mid);
                    j = mid-1;
                }
                else{
                    i = mid +1;
                }
            }
        return i;
    }
};