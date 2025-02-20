//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            int[] nums = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                nums[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            ArrayList<Double> ans = ob.getMedian(nums);
            for (double i : ans) {
                System.out.printf("%.1f ", i);
            }
            System.out.println();
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    void addNum(int num, PriorityQueue<Integer>maxHeap, PriorityQueue<Integer>minHeap){
        if(minHeap.isEmpty() || num <= maxHeap.peek()){
            maxHeap.add(num);
        }
        else{
            minHeap.add(num);
        }
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.add(maxHeap.poll());
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.add(minHeap.poll());
        }
    }
    
    double FindMedian(PriorityQueue<Integer>maxHeap, PriorityQueue<Integer>minHeap){
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.peek();
        }
        else{
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        }
    }
    
    public ArrayList<Double> getMedian(int[] arr) {
        // code here
        ArrayList<Double> result = new ArrayList();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int i : arr){
            addNum(i, maxHeap, minHeap);
            result.add(FindMedian(maxHeap, minHeap));
        }
        return result;
    }
}