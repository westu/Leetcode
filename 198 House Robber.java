public class Solution {
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        long[] moneySum = new long[nums.length];
        moneySum[0] = nums[0];
        moneySum[1] = nums[1];
        long prevMax = nums[0];
        for (int i = 2; i < nums.length; ++i) {
            prevMax = Math.max(prevMax, moneySum[i - 2]);
            moneySum[i] = prevMax + nums[i];
        }
        long ans = 0;
        for (long money : moneySum) {
            ans = Math.max(money, ans);
        }
        return ans;
    }
}
