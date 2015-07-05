class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exist_num;
        for (int i = 0; i < nums.size(); i++) {
            if (exist_num.find(target - nums.at(i)) != exist_num.end()) {
                vector<int> ans;
                ans.push_back(exist_num[target - nums.at(i)] + 1);
                ans.push_back(i + 1);
                return ans;
            }
            else {
                exist_num[nums.at(i)] = i;
            }
        }
    }
};
