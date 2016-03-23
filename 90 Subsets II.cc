class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > ans;
        vector<int> sub_set;
        ans.push_back(sub_set);
        if (nums.empty() == true) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        dfs(ans, nums, 0, false, sub_set);
        return ans;
    }

private:
    void dfs(vector<vector<int> > &ans, const vector<int> &nums, int w,
             bool prev_used, vector<int> &sub_set) {
        if (w == static_cast<int>(nums.size())) {
            return;
        }
        dfs(ans, nums, w + 1, false, sub_set);  // dont choose this one
        if (w > 0 && nums.at(w) == nums.at(w - 1) && prev_used == false) {
            // cant choose this one otherwise the solution will contain duplicate subsets
        } else {
            sub_set.push_back(nums.at(w));
            ans.push_back(sub_set);
            dfs(ans, nums, w + 1, true, sub_set);
            sub_set.pop_back();
        }
    }
};
