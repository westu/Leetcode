class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        map<int, int> max_sub_len;
        vector<int> last_num(nums.size(), 1 << 30);
        int ans = 0;
        for (int num : nums) {
            if (max_sub_len.empty()) {
                max_sub_len.insert(make_pair(num, 1));
                last_num.at(0) = num;
                ans = 1;
                continue;
            }
            auto it = max_sub_len.lower_bound(num);
            if (it == max_sub_len.begin()) {
                if (num < last_num.at(1 - 1)) {
                    max_sub_len.erase(last_num.at(1 - 1));
                    max_sub_len.insert(make_pair(num, 1));
                    last_num.at(1 - 1) = num;
                }
                ans = std::max(ans, 1);
            } else {
                --it;
                int now_len = it->second + 1;
                ans = std::max(ans, now_len);
                
                if (num < last_num.at(now_len - 1)) {
                    max_sub_len.erase(last_num.at(now_len - 1));
                    max_sub_len.insert(make_pair(num, now_len));
                    last_num.at(now_len - 1) = num;
                }
            }
        }
        return ans;
    }
};
