public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        if (strs.length != pattern.length()) {
            return false;
        }
        HashMap<Character, String> hashMap = new HashMap<Character, String>();
        for (int i = 0; i < pattern.length(); ++i) {
            if (hashMap.containsKey(pattern.charAt(i))) {
                if (!hashMap.get(pattern.charAt(i)).equals(strs[i])) {
                    return false;
                }
            } else {
                if (hashMap.containsValue(strs[i])) {
                    return false;
                }
                hashMap.put(pattern.charAt(i), strs[i]);
            }
        }
        return true;
    }
}
