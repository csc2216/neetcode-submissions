class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_price, cur_low = prices[0], cur_high = prices[0], 
        past_profit = 0, cur_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            cur_price = prices[i];
            if (cur_price < cur_low) {
                cur_low = cur_price;
                cur_high = cur_price;
                past_profit = max(past_profit, cur_profit);
            } else if (cur_price > cur_high) {
                cur_high = cur_price;
                cur_profit = cur_high - cur_low;
            }
        }
        return max(past_profit, cur_profit);
    }
};
