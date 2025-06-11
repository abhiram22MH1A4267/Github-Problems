class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n = color.size(), count = 0;
        stack<int>st1, st2;
        st1.push(color[0]);
        st2.push(radius[0]);
        for(int i = 1; i < n; i++){
            if(st1.empty()){
                st1.push(color[i]);
                st2.push(radius[i]);
            }
            else{
                if((st1.top() ==color[i]) && (st2.top() == radius[i])){
                    st1.pop();
                    st2.pop();
                }
                else{
                    st1.push(color[i]);
                    st2.push(radius[i]);
                }
            }
        }
        return st1.size();
    }
};