class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            unordered_map<int, int>::iterator hash_map_it =
                hash_map.find(nums.at(i));
            if (hash_map_it == hash_map.end()) {
                hash_map.insert(make_pair(nums.at(i), i));
            } else {
                if (i - hash_map_it->second <= k) {
                    return true;
                } else {
                    hash_map_it->second = i;
                }
            }
        }
        return false;
    }
};
