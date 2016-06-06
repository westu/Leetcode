public class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> charMap = new HashMap<Character, Character>();
        HashSet<Character> isMapped = new HashSet<Character>();
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); ++i) {
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if (charMap.containsKey(cs)) {
                if (charMap.get(cs) != ct) {
                    return false;
                }
            } else {
                if (isMapped.contains(ct)) {
                    return false;
                } else {
                    charMap.put(cs, ct);
                    isMapped.add(ct);
                }
            }
        }
        return true;
    }
}
