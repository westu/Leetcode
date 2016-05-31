public class Solution {
    public int trailingZeroes(int n) {
        int num = 0;
        while (n > 0) {
            num = num + n / 5;
            n = n / 5;
        }
        return num;
    }
}
