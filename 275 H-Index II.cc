class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = static_cast<int>(citations.size());
        int l(0), r(len), ans(0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            int h = len - mid;
            if (citations.at(mid) < h) {
                l = mid + 1;
            } else if (mid > 0 && citations.at(mid - 1) > h) {
                r = mid;
            } else {
                ans = max(ans, h);
                l = mid + 1;
            }
        }
        return ans;
    }
};
