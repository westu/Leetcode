/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int l(1), r(n + 1), ans(n);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (SVNRepo::isBadVersion(mid) == true) {
                ans = min(ans, mid);
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
