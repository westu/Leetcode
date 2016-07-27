class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l(0), r(nums.size());
        while (l < r) {
            if (l == r - 1) {
                break;
            }
            int mid = l + (r - l) / 2;
            int count =0;
            for (int n : nums) {
                if (n < mid) {
                    ++count;
                }
            }
            if (count < mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
