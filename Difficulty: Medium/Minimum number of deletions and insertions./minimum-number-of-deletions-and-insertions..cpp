//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	
	int dp[1002][1002];
	
	int solve(string str1, string str2, int i, int j, int n, int m){
	    if(i >= n || j >= m){
	        return 0;
	    }
	    if(dp[i][j] != -1) return dp[i][j];
	    if(str1[i] == str2[j]) return dp[i][j] = 1+ solve(str1,str2,i+1,j+1,n,m);
	    return dp[i][j] = max(solve(str1,str2,i+1,j,n,m), solve(str1,str2,i,j+1,n,m));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    memset(dp,-1,sizeof(dp));
	    int lcs = solve(str1,str2, 0, 0, n, m);
	    int ans = n+m-(2*lcs);
	    return ans;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends