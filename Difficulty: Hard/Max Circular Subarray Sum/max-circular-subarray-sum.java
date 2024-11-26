//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {

    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    public int circularSubarraySum(int arr[]) {

        // Your code here
        int s = 0, maxsum = Integer.MIN_VALUE, minsum = Integer.MAX_VALUE, curr = 0, currNeb = 0;
        for(int i : arr){
            s += i;
            curr = Math.max(curr+i, i);
            maxsum = Math.max(curr, maxsum);
            currNeb =  Math.min(i, currNeb+i);
            minsum = Math.min(currNeb, minsum);
        }
        if(s == minsum){
            return maxsum;
        }
        return Math.max(maxsum, s - minsum);
    }
}
