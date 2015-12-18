class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        vector<vector<int>> ans;
        if (size < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= (size - 3); i++) {
            if (i ==0 || nums[i] != nums[i - 1]) {
                int l = i + 1;
                int r = size - 1;
                while (l < r) {
                    if (nums[l] + nums[r] == -nums[i]) {
                        vector<int> tmp(3);
                        tmp[0] = nums[i];
                        tmp[1] = nums[l];
                        tmp[2] = nums[r];
                        ans.push_back(tmp);
                        while (nums[l] == tmp[1] && l < size) {
                            l++;
                        }
                    } else if (nums[l] + nums[r] < -nums[i]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
