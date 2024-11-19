//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine()); // Number of test cases
        while (tc-- > 0) {
            String[] inputLine = br.readLine().split(" ");
            int[] arr = new int[inputLine.length];
            for (int i = 0; i < inputLine.length; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            int N = arr.length;
            Solution ob = new Solution();
            ob.nextPermutation(arr); // Generate the next permutation
            StringBuilder out = new StringBuilder();
            for (int i = 0; i < N; i++) {
                out.append(arr[i] + " "); // Corrected: use arr[i] instead of arr.get(i)
            }
            System.out.println(out.toString().trim()); // Print the output
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static void reverse(int[] arr, int i, int j){
        while(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    void nextPermutation(int[] arr) {
        // code here
        int i, n = arr.length;
        for(i = n-2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                break;
            }
        }
        if(i > -1){
            int nextMax = Integer.MAX_VALUE, nextpos = 0;
            for(int j = i+1; j < n; j++){
                if(arr[j] > arr[i] && arr[j] < nextMax){
                    nextMax = arr[j];
                    nextpos = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[nextpos];
            arr[nextpos] = temp;
            reverse(arr,i+1, n-1);
        }
        else{
            reverse(arr, 0, n-1);
        }
    }
}