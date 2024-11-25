//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String[] inputLine = br.readLine().split(" ");
            int n = inputLine.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            System.out.println(new Solution().maxProduct(arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    int maxProduct(int[] arr) {
        // code here
        int n = arr.length;
        int ans = Integer.MIN_VALUE;
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            l = (l == 0 ? 1 : l) * arr[i];
            r = (r == 0 ? 1 : r) * arr[n-i-1];
            ans = Math.max(ans, Math.max(l,r));
        }
        return ans;
    }
}