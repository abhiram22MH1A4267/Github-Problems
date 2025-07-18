

// User function Template for Java

class Solution {
    int[] printKClosest(int[] arr, int k, int x) {
        // code here
        int n = arr.length;
        int id1 = findcrossover(arr,0,n-1,x);
        int id2 = id1+1;
        if(arr[id1] == x) id1--;
        int ans[] = new int[k];
        for(int i = 0; i < k; i++){
            if(id1 >= 0 && id2 < n) {
                int val1 = x-arr[id1], val2 = arr[id2]-x;
                if(val1 < val2){
                    ans[i] = arr[id1];
                    id1--;
                }
                else{
                    ans[i] = arr[id2];
                    id2++;
                }
            }
            else if(id1 >= 0){
                ans[i] = arr[id1];
                id1--;
            }
            else{
                ans[i] = arr[id2];
                id2++;
            }
        }
        return ans;
    }
    private int findcrossover(int[] arr, int low, int high, int x){
        if(arr[high] <= x) return high;
        if(arr[low] > x) return low;
        int mid = (high+low)/2;
        if(arr[mid] <= x && arr[mid+1] > x){
            return mid;
        }
        else if(arr[mid] < x) return findcrossover(arr,mid+1,high,x);
        return findcrossover(arr,low,mid-1,x);
    }
}
