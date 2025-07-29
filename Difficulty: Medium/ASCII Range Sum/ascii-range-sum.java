class Solution {
    public ArrayList<Integer> asciirange(String s) {
        ArrayList<Integer> res = new ArrayList<>();
        int n = s.length();
        int first[] = new int [26];
        int last[] = new int [26];
        
        Arrays.fill(first,-1);
         Arrays.fill(last,-1);
        
        
        for(int i=0; i<n ;i++){
            int j = s.charAt(i)-'a';
            if(first[j]==-1)
            first[j] =i;
            else 
             last[j] = i;
        }
        
         for(int i=0; i<26 ;i++){
             if (first[i] != -1 && last[i] != -1 && last[i] - first[i] > 1) {
                 int curr_sum=0;
                 for(int j = first[i]+1 ; j<last[i]; j++){
                     curr_sum += s.charAt(j);
                 }
                 res.add(curr_sum);
             }
         }
         return res;
        
    }
}