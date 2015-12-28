class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        if (len <= 1) {
            return;
        }
        bool ascending_check = false;
        int cur, prev;
        map<int, int> sto;
        for (cur = len - 1, prev = cur - 1; prev >= 0; --cur, --prev) {
            sto.insert(make_pair(nums[cur], cur));
            if (nums[prev] < nums[cur]) {
                ascending_check = true;
                int exch_ind = (*sto.upper_bound(nums[prev])).second;
                int tmp = nums[prev];
                nums[prev] = nums[exch_ind];
                nums[exch_ind] = tmp;
                sort(nums.begin() + cur, nums.end());
                return;
            }
        }
        if (ascending_check == false) {
            sort(nums.begin(), nums.end());
            return;
        }
    }
};
