public class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            --n;
            sb.append((char)((int)'A' + (n % 26)));
            n = n / 26;
        }
        return sb.reverse().toString();
    }
}
