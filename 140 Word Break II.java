public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        HashMap<String, ArrayList<String>> hashMap =
            new HashMap<String, ArrayList<String>>();
        return dfs(s, wordDict, hashMap);
    }

    private ArrayList<String> dfs(String s, Set<String> wordDict, HashMap<String, ArrayList<String>> hashMap) {
        if (hashMap.containsKey(s)) {
            return hashMap.get(s);
        }
        ArrayList<String> result = new ArrayList<String>();
        if (s.length() == 0) {
            return result;
        }
        for (int i = 1; i <= s.length(); ++i) {
            String tmpStr = s.substring(0, i);
            if (wordDict.contains(tmpStr)) {
                if (i == s.length()) {
                    result.add(tmpStr);
                } else {
                    String leftStr = s.substring(i, s.length());
                    ArrayList<String> partResult = dfs(leftStr, wordDict, hashMap);
                    for (String str : partResult) {
                        result.add(tmpStr + " " + str);
                    }
                }
            }
        }
        hashMap.put(s, result);
        return result;
    }
}
