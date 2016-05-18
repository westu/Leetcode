public class Solution {
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {
        if (wordList.isEmpty()) {
            return 0;
        }
        Queue<BfsStatus> queue = new LinkedList<BfsStatus>();
        HashSet<String> isChosen = new HashSet<String>();
        queue.offer(new BfsStatus(beginWord, 0));
        isChosen.add(beginWord);
        while (!queue.isEmpty()) {
            BfsStatus status = queue.poll();
            if (oneCharDiff(status.word, endWord)) {
                return status.steps + 2;
            }
            for (String word : wordList) {
                if (isChosen.contains(word) == false
                    && oneCharDiff(word, status.word)) {
                    isChosen.add(word);
                    queue.offer(new BfsStatus(word, status.steps + 1));
                }
            }
        }
        return 0;
    }

    private class BfsStatus {
        String word;
        int steps;
        BfsStatus(String word, int steps) {
            this.word = word;
            this.steps = steps;
        }
    }
    
    private boolean oneCharDiff(String word1, String word2) {
        int diffNum = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (word1.charAt(i) != word2.charAt(i)) {
                ++diffNum;
                if (diffNum > 1) {
                    return false;
                }
            }
        }
        return diffNum == 1;
    }
}
