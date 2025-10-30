class Solution {
    public int maxCircularSum(int arr[]) {
        // code here
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
