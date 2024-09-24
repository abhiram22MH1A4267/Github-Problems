//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int min_len = INT_MAX;
        int s_index = -1;
        int r = 0, l = 0;
        vector<int>mp(256,0);
        for(int i = 0; i < p.size(); i++){
            mp[p[i]]++;
        }
        int cnt = 0;
        while(r < s.length()){
            if(mp[s[r]] > 0){
                cnt++;
            }
            mp[s[r]]--;
            while(cnt == p.length()){
                if(r-l+1 < min_len){
                    min_len = r-l+1;
                    s_index = l; 
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return s_index == -1 ? "-1" : s.substr(s_index, min_len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends