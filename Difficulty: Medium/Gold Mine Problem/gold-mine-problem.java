class Solution {
    private int solve(int i, int j, int[][] mat, int[][] dp) {
        int n = mat.length;
        int m = mat[0].length;

        if (i < 0 || i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int rightUp = solve(i - 1, j + 1, mat, dp);
        int right = solve(i, j + 1, mat, dp);
        int rightDown = solve(i + 1, j + 1, mat, dp);
        
        return dp[i][j] = mat[i][j] + Math.max(right, Math.max(rightUp, rightDown));
    }
    
    public int maxGold(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int result = 0;
        int[][] dp = new int[501][501];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        for (int i = 0; i < n; i++) {
            result = Math.max(result, solve(i, 0, mat, dp));
        }
        return result;
    }
}
