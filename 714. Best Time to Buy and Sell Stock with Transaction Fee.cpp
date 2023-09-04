class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int buy = -prices[0]; 
        int sell = 0;
        
        for (int i = 1; i < n; ++i) {
            int newBuy = max(buy, sell - prices[i]);
            
            int newSell = max(sell, buy + prices[i] - fee);
            
            buy = newBuy;
            sell = newSell;
        }
        
        return sell;
    }
};
