bool cmp(const pair<int,int> p,const pair<int, int> q) {
    return p.first < q.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*unordered_map<int, int> exist_num;
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
        }*/
        int len = static_cast<int>(nums.size());
        vector<pair<int, int>> num_ind(len);
        for (int i = 0; i < len; i++) {
            num_ind[i] = make_pair(nums[i], i + 1);
        }
        sort(num_ind.begin(), num_ind.end(), cmp);
        int l, r;
        l = 0;
        r = len - 1;
        while (l < r) {
            int sum = num_ind[l].first + num_ind[r].first;
            if (sum == target) {
                vector<int> ans(2);
                ans[0] = min(num_ind[l].second, num_ind[r].second);
                ans[1] = max(num_ind[l].second, num_ind[r].second);
                return ans;
            } else if (sum < target) {
                l ++;
            } else {
                r --;
            }
        }
    }
};
