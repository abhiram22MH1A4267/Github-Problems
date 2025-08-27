class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        int n = arr.size(), count = 0;
        
        for (int i = 2; i < n; ++i) {
      
            int left = 0, right = i - 1; 

            while (left < right) {
          
                if (arr[left] + arr[right] > arr[i]) {
                    count += right - left; 
                    right--; 
                } 
          	    else {
                    left++; 
                }
            }
        }
        
        return count;
    }
};
