class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if(n == 1) return 10;
        list<long long>l[10];
        l[0].assign({0,8});
        l[1].assign({1,2,4});
        l[2].assign({2,1,3,5});
        l[3].assign({3,6,2});
        l[4].assign({4,1,7,5});
        l[5].assign({5,4,6,2,8});
        l[6].assign({6,3,5,9});
        l[7].assign({7,4,8});
        l[8].assign({8,5,0,7,9});
        l[9].assign({9,6,8});
        long long count[10];
        for(int i = 0; i < 10; ++i){
            count[i] = 1;
        }
        for(int i = 2;i <= n; ++i){
            long long int counttemp[10] = {0};
            for(int j = 0; j < 10; ++j){
                for(int x : l[j]){
                    counttemp[x] += count[j];
                }
            }
            for(int j = 0; j < 10; ++j){
                count[j] = counttemp[j];
            }
        }
        long long ans = 0;
        for(int i = 0; i < 10; ++i){
            ans += count[i];
        }
        return ans;
    }
};