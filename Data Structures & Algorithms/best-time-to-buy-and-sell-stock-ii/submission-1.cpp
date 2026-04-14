class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(i + 1 < prices.size() && prices[i] < prices[i+1]) {
                maxProfit += prices[i+1] - prices[i];
            }
        }

        return maxProfit;
    }
};