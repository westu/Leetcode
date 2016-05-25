public class Solution {
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    public boolean wordBreak(String s, Set<String> wordDict) {
        boolean[] isOk = new boolean[s.length() + 1];
        isOk[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            isOk[i] = false;
            for (String w : wordDict) {
                if (i - w.length() >= 0
                    && isOk[i - w.length()] == true
                    && w.contentEquals(s.substring(i - w.length(), i)) == true) {
                    isOk[i] = true;
                    break;
                }
            }
        }
        return isOk[s.length()];
    }
}
