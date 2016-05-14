public class Solution {
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    public boolean isPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        int startPos = 0;
        int endPos = s.length() - 1;
        while (true) {
            while (startPos < endPos && !isAlphanumeric(s.charAt(startPos))) {
                ++startPos;
            }
            while (endPos > startPos && !isAlphanumeric(s.charAt(endPos))) {
                --endPos;
            }
            if (startPos >= endPos) {
                return true;
            }
            if (Character.toUpperCase(s.charAt(startPos))
                != Character.toUpperCase(s.charAt(endPos))) {
                return false;
            } else {
                ++startPos;
                --endPos;
            }
        }
    }

    private boolean isAlphanumeric(char ch) {
        return 'a' <= ch && ch <= 'z'
            || 'A' <= ch && ch <= 'Z'
            || '0' <= ch && ch <= '9';
    }
}
