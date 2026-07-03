class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int past_min = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - past_min);
            past_min = min(past_min, prices[i]);
        }
        return profit;
    }
};
