public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] nums) {
        Integer minValue = null;
        for (int num : nums) {
            if (minValue == null || minValue > num) {
                minValue = num;
            }
        }
        return minValue;
    }
}
