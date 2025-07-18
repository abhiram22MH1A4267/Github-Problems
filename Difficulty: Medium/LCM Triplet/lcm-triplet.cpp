class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n <= 2) return n;
        if((n % 2) == 0){
            if((n % 3) == 0) return ((n-1) * (n-2) * (n-3));
            else return ((n-1) * (n-3) * n);
        }
        else{
            return ((n-1) * (n-2) * n);
        }
    }
};