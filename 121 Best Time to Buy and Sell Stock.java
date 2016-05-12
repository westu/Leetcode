public class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        if (prices.length == 0 || prices.length == 1) {
            return 0;
        }
        int agoMinPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.length; ++i) {
            maxProfit = Math.max(maxProfit, prices[i] - agoMinPrice);
            agoMinPrice = Math.min(agoMinPrice, prices[i]);
        }
        return maxProfit;
    }
}
