class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>st;
        int n = s.length(), count = 0;
        for(char ch : s){
            if(ch == '(') st.push(ch);
            else if(!st.empty() && ch == ')' && st.top() == '(') st.pop();
            else count++;
        }
        int open = st.empty() ? 0 : st.size();
        return open + count;
    }
};