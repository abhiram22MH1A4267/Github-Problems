class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>prev(n,-1), next(n,n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prev[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                next[i] = st.top();
            }
            st.push(i);
        }
        
        vector<int>max_mins(n+1, 0);
        for(int i = 0; i < n; i++){
            int length = next[i] - prev[i] - 1;
            max_mins[length] = max(max_mins[length], arr[i]);
        }
        for(int i = n-1; i >= 0; i--){
            max_mins[i] = max(max_mins[i], max_mins[i+1]);
        }
        
        vector<int>ans(max_mins.begin()+1, max_mins.end());
        return ans;
    }
};