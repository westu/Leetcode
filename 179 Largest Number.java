public class Solution {
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    public String largestNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            strs[i] = Integer.toString(nums[i]);
        }
        Arrays.sort(strs, new IntComparator());
        StringBuilder ans = new StringBuilder();
        for (String str : strs) {
            ans.append(str);
        }
        while (ans.length() >= 2 && ans.charAt(0) == '0') {
            ans.deleteCharAt(0);
        }
        return ans.toString();
    }

    class IntComparator implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            return (s2 + s1).compareTo(s1 + s2);
        }
    }
}
