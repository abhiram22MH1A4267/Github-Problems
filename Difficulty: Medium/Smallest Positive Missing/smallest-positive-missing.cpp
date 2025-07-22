class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int maxEle = *max_element(arr.begin(), arr.end());
        maxEle = maxEle > 0 ? maxEle : 1;
        vector<int>freq(maxEle+1, 0);
        for(int i : arr){
            if(i > 0) freq[i]++;
        }
        
        for(int i = 1; i <= maxEle; i++){
            if(freq[i] == 0) return i;
        }
        return maxEle + 1;
    }
};