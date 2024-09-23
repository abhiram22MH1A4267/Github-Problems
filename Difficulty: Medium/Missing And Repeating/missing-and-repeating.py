#User function Template for python3

class Solution:
    def findTwoElement( self,arr): 
        # code here
        d = {}
        a = []
        for i in arr:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        for i in d.keys():
            if d[i] > 1:
                a.append(i)
        j = sorted(d)
        k = 1
        for i in range(len(j)):
            if k != j[i]:
                a.append(k)
                break
            k+=1
        if len(a) == 2:
            return a
        else:
            a.append(j[len(j)-1]+1)
            return a
        
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends