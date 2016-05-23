public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.length;
        while (true) {
            if (nums[left] <= nums[right - 1]) {
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                ++left;
                right = mid + 1;
            }
        }
    }
}
