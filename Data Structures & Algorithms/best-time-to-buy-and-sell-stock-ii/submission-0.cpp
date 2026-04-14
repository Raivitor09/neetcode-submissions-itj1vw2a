class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit = 0, maxProfit = 0;
        int i = 0, j = i + 1;

        while(j < prices.size()) {
            if(prices[i] < prices[j]) {
                currProfit += prices[j] - prices[i];
                maxProfit = max(maxProfit, currProfit);
                i++, j++;
            } else {
                i = j;
                j++;
            }
        }

        return maxProfit;
    }
};