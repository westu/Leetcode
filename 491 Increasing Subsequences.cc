class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty() || nums.size() == 1) {
            return ans;
        }
        vector<int> one_list;
        set<vector<int>> list_tag;
        dfs(nums, one_list, 0, ans, list_tag);
        return ans;
    }
private:
    void dfs(const vector<int> &nums, vector<int> &one_list, int pos,
        vector<vector<int>> &ans, set<vector<int>> &list_tag) {
        if (pos == nums.size()) {
            if (one_list.size () >= 2 && list_tag.find(one_list) == list_tag.end()) {
                ans.push_back(one_list);
                list_tag.insert(one_list);
                return;
            }
        } else {
            if (one_list.empty() || nums.at(pos) >= one_list.back()) {
                one_list.push_back(nums.at(pos));
                dfs(nums, one_list, pos + 1, ans, list_tag);
                one_list.pop_back();
            }
            dfs(nums, one_list, pos + 1, ans, list_tag);
        }
    }
};
