public class Solution {
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        int maxLength = 0;
        for (int num : nums) {
            hashSet.add(num);
        }
        for (int num : nums) {
            int left = num - 1;
            while (hashSet.contains(left)) {
                hashSet.remove(left);
                --left;
            }
            int right = num + 1;
            while (hashSet.contains(right)) {
                hashSet.remove(right);
                ++right;
            }
            maxLength = Math.max(maxLength, right - 1 - left);
        }
        return maxLength;
    }
}
