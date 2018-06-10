class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> hash_map;
        if (t < 0) {
            return false;
        }
        for (int i = 0, j = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i - j > k) {
                --hash_map[nums.at(j)];
                if (hash_map[nums.at(j)] == 0) {
                    hash_map.erase(nums.at(j));
                }
                ++j;
            }
            
            if (!hash_map.empty()) {
                t = abs(t);
                auto it = hash_map.upper_bound((long long)nums.at(i) + t);
                auto it2 = hash_map.lower_bound((long long)nums.at(i) - t);
                if (it != it2) {
                    return true;
                }
            }
            ++hash_map[nums.at(i)];
        }
        return false;
    }
};
