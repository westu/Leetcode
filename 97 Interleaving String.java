public class Solution {
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true or false.
     */
  public boolean isInterleave(String s1, String s2, String s3) {
    if (s3.length() != s1.length() + s2. length()) {
      return false;
    }
    boolean[][] isInterleave = new boolean[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i <= s1.length(); ++i) {
      Arrays.fill(isInterleave[i], false);
    }
    isInterleave[0][0] = true;
    for (int i = 1; i <= s1.length(); ++i) {
      isInterleave[i][0] = s1.charAt(i - 1) == s3.charAt(i - 1) && isInterleave[i - 1][0];
    }
    for (int i = 1; i <= s2.length(); ++i) {
      isInterleave[0][i] = s2.charAt(i - 1) == s3.charAt(i - 1) && isInterleave[0][i - 1];
    }
    for (int i = 1; i <= s1.length(); ++i) {
      for (int j = 1; j <= s2.length(); ++j) {
        isInterleave[i][j] =
            s1.charAt(i - 1) == s3.charAt(i + j - 1) && isInterleave[i - 1][j] ||
            s2.charAt(j - 1) == s3.charAt(i + j - 1) && isInterleave[i][j - 1];
      }
    }
    return isInterleave[s1.length()][s2.length()];
  }

  /*
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s3.length() != s1.length() + s2. length()) {
            return false;
        }
        return dfs(s1, 0, s2, 0, s3, 0);
    }

    private boolean dfs(String s1, int n1, String s2, int n2, String s3, int n3) {
        if (n3 == s3.length()) {
            return true;
        }
        if ((n1 < s1.length()) &&
            (s3.charAt(n3) == s1.charAt(n1)) &&
            (dfs(s1, n1 + 1, s2, n2, s3, n3 + 1))) {
            return true;   
        }
        if ((n2 < s2.length()) &&
            (s3.charAt(n3) == s2.charAt(n2)) &&
            (dfs(s1, n1, s2, n2 + 1, s3, n3 + 1))) {
            return true;
        }
        return false;
    }
   */
}
