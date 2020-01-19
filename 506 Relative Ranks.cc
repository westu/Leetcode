class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> return_list;
        if (nums.empty()) {
            return return_list;
        }
        
        vector<int> sort_nums(nums);
        sort(sort_nums.begin(), sort_nums.end(), greater<int>());
        
        for (int num : nums) {
            int pos = binary_search_pos(sort_nums, num);
            if (pos == 0) {
                return_list.push_back("Gold Medal");
            } else if (pos == 1) {
                return_list.push_back("Silver Medal");
            } else if (pos == 2) {
                return_list.push_back("Bronze Medal");
            } else {
                return_list.push_back(to_string(pos + 1));
            }
        }
        
        return return_list;
    }
    
private:
    int binary_search_pos(const vector<int> &nums, int num) {
        if (nums.empty()) {
            return -1;
        }
        int l(0), r(static_cast<int>(nums.size()));
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums.at(mid) == num) {
                return mid;
            }
            if (nums.at(mid) > num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;  // not found
    }
};
