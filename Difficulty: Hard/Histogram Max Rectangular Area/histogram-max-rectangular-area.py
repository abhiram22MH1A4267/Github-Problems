#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

class Solution:
    def getMaxArea(self,arr):
        #code here
        n = len(arr)
        s, l, r = [], [-1] * n, [n] * n;
        for i in range(n):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                l[i] = s[-1]
            s.append(i)
        s.clear()
        for i in range(n-1,-1,-1):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            if s:
                r[i] = s[-1]
            s.append(i)
        m = 0
        for i in range(n):
            m = max(m, arr[i] * (r[i]-l[i]-1))
        return m

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.getMaxArea(arr)
        print(res)
        print("~")
        t -= 1


# } Driver Code Ends