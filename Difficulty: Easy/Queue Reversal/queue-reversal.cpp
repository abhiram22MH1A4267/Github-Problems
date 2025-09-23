class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        vector<int>arr;
        while(!q.empty()){
            arr.push_back(q.front());
            q.pop();
        }
        reverse(arr.begin(), arr.end());
        for(int i : arr){
            q.push(i);
        }
        
    }
};