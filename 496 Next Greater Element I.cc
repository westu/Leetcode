class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        if (findNums.empty()) {
            return ans;
        }
        unordered_map<int, int> index_map;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            index_map.insert(make_pair(nums.at(i), i));
        }
        
        for (int i = 0; i < static_cast<int>(findNums.size()); ++i) {
            bool flag = false;
            for (int j = index_map.find(findNums.at(i))->second + 1; j < static_cast<int>(nums.size()); ++j) {
                if (nums.at(j) > findNums.at(i)) {
                    ans.push_back(nums.at(j));
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
