class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        int l = static_cast<int>(nums.size());
        vector<int> counter(l, 1);
        vector<int> prev_num_record(l, -1);
        int max_size(0), last_index(0);
        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums.at(i) % nums.at(j) == 0 && counter.at(j) + 1 > counter.at(i)) {
                    counter.at(i) = counter.at(j) + 1;
                    prev_num_record.at(i) = j;
                }
            }
            
            if (counter.at(i) > max_size) {
                max_size = counter.at(i);
                    last_index = i;
            }
        }
        
        while (last_index != -1) {
            ans.push_back(nums.at(last_index));
            last_index = prev_num_record.at(last_index);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
