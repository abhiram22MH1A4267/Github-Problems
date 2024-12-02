//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s, patt;
            s = sc.next();
            patt = sc.next();

            Solution ob = new Solution();

            ArrayList<Integer> res = ob.search(patt, s);
            if (res.size() == 0)
                System.out.print("[]");
            else {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    ArrayList<Integer> search(String pat, String txt) {
        // your code here
        ArrayList<Integer> result = new ArrayList();
        int[] lps = new int[pat.length()];
        calculateLPS(pat, lps);
        int i = 0, j = 0, f = 0;
        int n = txt.length();
        while(i < n){
            if(pat.charAt(j) == txt.charAt(i)){
                i++;
                j++;
            }
            if(j == pat.length()){
                f++;
                result.add(i-j);
                j = lps[j-1];
            }
            else if(i< n && pat.charAt(j) != txt.charAt(i)){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i = i+1;
                }
            }
        }
        return result;
    }
    void calculateLPS(String pat, int[] lps){
        int n = pat.length();
        int len = 0, i = 1;
        while(i < n){
            if(pat.charAt(i) == pat.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
}