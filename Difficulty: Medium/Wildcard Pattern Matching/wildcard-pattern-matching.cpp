class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.length(), m = pat.length();
        int i = 0, j = 0, startIndex = -1, match = 0;
    
        while (i < n) {
            if (j < m && (pat[j] == '?' || pat[j] == txt[i])) {          
                i++;
                j++;
            }
            
            else if (j < m && pat[j] == '*') {
                startIndex = j;
                match = i;
                j++;
            }
          
            else if (startIndex != -1) {
                j = startIndex + 1;
                match++;
                i = match;
            }
            
            else {
                return false;
            }
        }
        
        while (j < m && pat[j] == '*') {
            j++;
        }
    
        return j == m;
    }
};