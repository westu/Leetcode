class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int len = static_cast<int>(nums.size());
        if (len == 0) {
            return 0;
        }
        int l, r;
        l = 0;
        r = 1;
        while (r < len) {
            while (nums[r] == nums[l] && r < len) {
                r++;
            }
            if (r < len) {
                int tmp = nums[r];
                nums[r] = nums[l + 1];
                nums[l + 1] = tmp;
                l++;
                r++;
            }
        }
        return (l + 1);
    }
};
