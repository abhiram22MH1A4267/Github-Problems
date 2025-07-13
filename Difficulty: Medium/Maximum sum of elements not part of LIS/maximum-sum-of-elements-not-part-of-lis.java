class Solution {
    public int nonLisMaxSum(int[] arr) {
        int n     = arr.length;
        int total = 0;

        for (int v : arr) {
            total += v;
        }

        int[] dp       = new int[n];
        int[] dpMinSum = new int[n]; 
        for (int i = 0; i < n; i++) {
            dp[i] = 1; 
            dpMinSum[i] = arr[i];
        }

        int maxLIS    = 1; 
        int minLISsum = arr[0]; 

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    int currLen = dp[j] + 1; 
                    int currSum = dpMinSum[j] + arr[i];

                    if (currLen > dp[i]) {
                        dp[i]       = currLen;
                        dpMinSum[i] = currSum;
                    } else if (currLen == dp[i]) {
                        
                        dpMinSum[i] = Math.min(dpMinSum[i], currSum);
                    }
                }
            }
            
            if (dp[i] > maxLIS) {
                maxLIS    = dp[i];
                minLISsum = dpMinSum[i];
            } else if (dp[i] == maxLIS) {
                minLISsum = Math.min(minLISsum, dpMinSum[i]);
            }
        }

        return total - minLISsum;
    }
}