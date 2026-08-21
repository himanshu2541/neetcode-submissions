class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best_buy = INT_MAX;
        int max_profit = 0;
        
        for(int price: prices){
            best_buy = min(price, best_buy);
            max_profit = max(max_profit, price - best_buy);
        }

        return max_profit;
    }
};
