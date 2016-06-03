public class Solution {
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    public boolean isHappy(int n) {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        while (n != 1) {
            if (hashSet.contains(n)) {
                return false;
            }
            hashSet.add(n);
            int m = 0;
            while (n > 0) {
                m = m + (n % 10) * (n % 10);
                n = n / 10;
            }
            n = m;
        }
        return true;
    }
}
