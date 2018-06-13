class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
//         vector<vector<int>> ans;
//         if (nums.empty() || nums.size() == 1) {
//             return ans;
//         }
//         vector<int> one_list;
//         set<vector<int>> list_tag;
//         dfs(nums, one_list, 0, ans, list_tag);
//         return ans;
      vector<vector<int>> candidates;
      if (nums.empty()) {
        return candidates;
      }
      set<vector<int>> res;
      candidates.push_back(vector<int>());
        
      for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int n = static_cast<int>(candidates.size());
        for (int j = 0; j < n; ++j) {
          if (candidates.at(j).empty() || candidates.at(j).back() <= nums.at(i)) {
            candidates.push_back(candidates.at(j));
            candidates.back().push_back(nums.at(i));
            if (static_cast<int>(candidates.back().size()) >= 2) {
              res.insert(candidates.back());
            }
          }
        }
      }
      return vector<vector<int>>(res.begin(), res.end());
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
