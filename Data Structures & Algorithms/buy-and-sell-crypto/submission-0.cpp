class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);  // Atualiza o menor preço até agora
            maxProfit = max(maxProfit, price - minPrice);  // Calcula o lucro máximo possível
        }

        return maxProfit;
    }
};
