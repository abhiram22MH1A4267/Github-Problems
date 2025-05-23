class Solution {
  public:
    int dp[51][51];
    int solve(int m, int n, int x){
        if(x < 0) return 0;
        if(dp[n][x] != -1) return dp[n][x];
        if(n == 0 && x == 0) return 1;
        if(n == 0) return 0;
        int result = 0;
        for(int i = 1; i <= m; i++){
            result += solve(m, n-1, x-i);
        }
        return dp[n][x] = result;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(m, n, x);
    }
};