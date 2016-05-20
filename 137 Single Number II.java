public class Solution {
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    public int singleNumberII(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int sumAtThisDigit = 0;
            for (int n : nums) {
                sumAtThisDigit = sumAtThisDigit + ((n >> i) & 1);
                sumAtThisDigit = sumAtThisDigit % 3;
            }
            ans = ans + (sumAtThisDigit << i);
        }
        return ans;
    }
}
