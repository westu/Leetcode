public class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        int pow26 = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            ans =  ans + ((int)s.charAt(i) - (int)'A' + 1) * pow26;
            pow26 = pow26 * 26;
        }
        return ans;
    }
}
