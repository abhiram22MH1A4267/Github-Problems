# User function Template for python3

class Solution:
    
    #Function to reverse words in a given string.
    def reverseWords(self,str):
        # code here 
        l=s.split('.')
        s1=""
        for i in range(len(l)-1,0,-1):
            s1+="".join(l[i])+'.'
        return s1+l[0]


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        obj = Solution()
        print(obj.reverseWords(s))

# } Driver Code Ends