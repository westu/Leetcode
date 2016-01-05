class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.empty() == true) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()) == true);
        return ans;
    }
};
