class Solution {
  public:
    string decodedString(string &s) {
        // code here
        s = "1[" + s + "]";
        stack<pair<string, int>>st;
        int val = 0;
        string str = "";
        for(char ch : s){
            if(ch == '['){
                st.push({"", val});
                val = 0;
            }
            else if(ch == ']'){
                string total = "";
                for(int i = 0; i < st.top().second; i++){
                    total += st.top().first;
                }
                st.pop();
                if(st.empty()){
                    return total;
                }
                else{
                    st.top().first += total;
                }
            }
            else if(ch >= 'a' && ch <= 'z'){
                st.top().first += ch;
            }
            else{
                val *= 10;
                val += (ch - '0');
            }
        }
        return "";
    }
};