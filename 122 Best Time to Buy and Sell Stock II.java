class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) {
            return 0;
        }
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] < prices[i - 1]) {
                ans = ans + Math.max(prices[i - 1] - minPrice, 0);
                minPrice = prices[i];
            }
        }
        ans = ans + Math.max(prices[prices.length - 1] - minPrice, 0);
        return ans;
    }
};
