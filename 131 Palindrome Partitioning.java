public class Solution {
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    public List<List<String>> partition(String s) {
        List<List<String>> ansSet = new LinkedList<>();
        if (s.length() == 0) {
            return ansSet;
        }
        LinkedList<String> ans = new LinkedList<String>();
        StringBuilder sBuilder = new StringBuilder();
        dfs(s, 0, 0, sBuilder, ansSet, ans);
        return ansSet;
    }

    private void dfs(String s,
        int subStrStart,
        int subStrEnd,
        StringBuilder sBuilder,
        List<List<String>> ansSet,
        LinkedList<String> ans) {
        if (subStrStart >= s.length()) {
            ansSet.add(new LinkedList(ans));
            return;
        }
        if (subStrEnd >= s.length()) {
            return;
        }
        sBuilder.append(s.charAt(subStrEnd));
        // String subStr = s.substring(subStrStart, subStrEnd + 1);
        if (isPalindrome(sBuilder)) {
            ans.add(sBuilder.toString());
            dfs(s, subStrEnd + 1, subStrEnd + 1, new StringBuilder(), ansSet, ans);
            ans.pollLast();
        }
        dfs(s, subStrEnd, subStrEnd + 1, sBuilder, ansSet, ans);
    }

    private boolean isPalindrome(StringBuilder s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
}
