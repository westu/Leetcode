public class Solution {
    public int countPrimes(int n) {
        --n;
        if (n <= 1) {
            return 0;
        }
        boolean[] isPrime = new boolean[n - 1];
        for (int i = 2; i <= n; ++i) {
            isPrime[i - 2] = true;
        }
        for (int i = 2; i <= n / 2; ++i) {
            if (isPrime[i - 2] == false) {
                continue;
            }
            for (int j = 2; i * j <= n; ++j) {
                isPrime[i * j - 2] = false;
            }
        }
        int count = 0;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i - 2]) {
                ++count;
            }
        }
        return count;
    }
}
