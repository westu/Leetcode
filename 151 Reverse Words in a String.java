public class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
    public String reverseWords(String s) {
        if (s.length() == 0) {
            return s;
        }
        ArrayList<String> sList = new ArrayList<String>();
        int startPos = 0;
        boolean nowIsWord = false;
        StringBuilder sb = new StringBuilder(s);
        sb.append(' ');
        for (int i = 0; i < sb.length(); ++i) {
            if (nowIsWord == false && sb.charAt(i) != ' ') {
                startPos = i;
                nowIsWord = true;
            } else if (nowIsWord == true && sb.charAt(i) == ' ') {
                sList.add(sb.substring(startPos, i));
                nowIsWord = false;
            }
        }
        sb = new StringBuilder();
        for (int i = sList.size() - 1; i >= 0; --i) {
            sb.append(sList.get(i));
            if (i > 0) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }
}
