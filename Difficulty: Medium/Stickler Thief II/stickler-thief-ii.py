class Solution:
    def maxValue(self, a):
        # code here
        n = len(a)
        if n == 1:
            return a[0]
        def rob(b, x, y):
            i,j = 0,0
            for k in range(x, y):
                i, j = j, max(j, i + b[k])
            return j
        return max(rob(a, 0, n-1), rob(a, 1, n))



#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self):
        arr = [int(i) for i in input().strip().split()]
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = IntArray().Input()

        obj = Solution()
        res = obj.maxValue(arr)

        print(res)
        print("~")

# } Driver Code Ends