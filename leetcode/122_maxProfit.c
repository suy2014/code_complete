class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;

        for (int i = 0; i < prices.size() - 1; ++i)
        {
            if ((prices[i + 1] -prices[i]) > 0) {
                max += prices[i + 1] -prices[i];
            }
        }
        return max;
    }
};
