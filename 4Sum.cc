class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((i == 0 || nums[i] != nums[i - 1]) && (j == i + 1 || nums[j] != nums[j - 1])) {
                    int l = j + 1;
                    int r = len - 1;
                    while (l < r) {
                        int sum = nums[i] + nums[j] + nums[l] + nums[r];
                        if (sum == target) {
                            vector<int> tmp(4);
                            tmp[0] = nums[i];
                            tmp[1] = nums[j];
                            tmp[2] = nums[l];
                            tmp[3] = nums[r];
                            while (l < len && nums[l] == tmp[2]) {
                                l++;
                            }
                            ans.push_back(tmp);
                        } else if (sum < target) {
                            l++;
                        } else {
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
