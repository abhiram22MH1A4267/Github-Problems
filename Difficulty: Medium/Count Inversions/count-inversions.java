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
            System.out.println(new Solution().inversionCount(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to count inversions in the array.
    static int merge(int[] arr, int le, int mid, int ri){
        int j = mid+1;
        int count = 0;
        for(int i = le; i <= mid; i++){
            while(j <= ri && arr[i] > arr[j]){
                j++;
            }
            count += j - (mid+1);
        }
        Arrays.sort(arr, le, ri+1);
        return count;
    }
    static int mergeSort(int[] arr, int le, int ri){
        if(le >= ri) return 0;
        int mid = (le + ri) / 2;
        int leftInversion = mergeSort(arr, le, mid);
        int rightInversion = mergeSort(arr, mid+1, ri);
        int m = merge(arr, le, mid, ri);
        return leftInversion + rightInversion + m;
    }
    static int inversionCount(int arr[]) {
        // Your Code Here
        return mergeSort(arr, 0, arr.length - 1);
    }
}