class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) {
            return 0;
        }
        int[] left = new int[prices.length];
        int[] right = new int[prices.length];

        int minPrice = prices[0];
        left[0] = 0;
        for (int i = 1; i < prices.length; ++i) {
            left[i] = Math.max(left[i - 1], prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }

        int maxPrice = prices[prices.length - 1];
        right[prices.length - 1] = 0;
        for (int i = prices.length - 2; i >= 0; --i) {
            right[i] = Math.max(right[i + 1], maxPrice - prices[i]);
            maxPrice = Math.max(maxPrice, prices[i]);
        }

        int ans = 0;
        for (int i = 0; i < prices.length; ++i) {
            ans = Math.max(ans, left[i] + right[i]);
        }
        return ans;
    }
};
