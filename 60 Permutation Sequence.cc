class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
       int w = 1;
        for (int i = 2; i <= n - 1; ++i) {
            w *= i;
        }
        vector<bool> used(n, false);
        string ans;
        for (int i = 1; i <= n; ++i) {
            int tmp = k % w == 0 ? k / w : k / w + 1;
            k -= (tmp - 1) * w;
            if (i < n) {
                w /= n - i;
            }
            for (int count = 0, j = 0; ; ++j) {
                if (used[j] == false) {
                    ++count;
                }
                if (count == tmp) {
                    ans.push_back('0' + j + 1);
                    used[j] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
