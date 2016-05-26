public class Solution {
    /**
     * @param nums: an array of integers
     * @return: an integer
     */
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] minList = new int[nums.length];
        int[] maxList = new int[nums.length];
        minList[0] = nums[0];
        maxList[0] = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int n1 = minList[i - 1] * nums[i];
            int n2 = maxList[i - 1] * nums[i];
            maxList[i] = Math.max(n1, n2);
            maxList[i] = Math.max(maxList[i], nums[i]);
            minList[i] = Math.min(n1, n2);
            minList[i] = Math.min(minList[i], nums[i]);
            maxP = Math.max(maxList[i], maxP);
        }
        return maxP;
    }
}
