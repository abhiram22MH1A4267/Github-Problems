class Solution {
  public:
    pair<int, int> largest(vector<int>&x, vector<int>&y){
        int largeNum = 0, index = 0, flag = 0;
        
        for(int i = 0; i < x.size(); i++){
            if(x[i] > largeNum){
                largeNum = x[i];
                index = i;
            }
        }
        
        for(int i = 0; i < y.size(); i++){
            if(y[i] > largeNum){
                largeNum = y[i];
                index = i;
                flag = 1;
            }
        }
        
        if(flag == 0){
            x.erase(x.begin() + index);
        }
        else{
            y.erase(y.begin() + index);
        }
        
        return {largeNum, flag};
    }
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int horizontal = 1, vertical = 1;
        
        int loop = n - 1 + m - 1;
        
        int result = 0;
        
        for(int i = 0; i < loop; i++){
            pair<int, int> cut = largest(x, y);
            
            if(cut.second == 0){
                result += (cut.first * horizontal);
                vertical++;
            }
            else{
                result += (cut.first * vertical);
                horizontal++;
            }
        }
        
        return result;
    }
};
