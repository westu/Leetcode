public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        int num = 0;
        int count = 0;
        for (int n : nums) {
            if (count == 0 || n == num) {
                num = n;
                ++count;
            } else {
                --count;
            }
        }
        return num;
    }
}
