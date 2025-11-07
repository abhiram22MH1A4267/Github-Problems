class Solution {
  public:
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        sort(jobs.begin(), jobs.end());
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int maxProfit = 0;
        
        for (auto &job : jobs) {
            int start = job[0], end = job[1], profit = job[2];
            
            while (!pq.empty() && pq.top().first <= start) {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }
            
            pq.push({end, profit + maxProfit});
        }
        
        while (!pq.empty()) {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }
        
        return maxProfit;
    }
};
