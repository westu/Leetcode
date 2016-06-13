class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int num : nums) {
            if (hash_set.find(num) != hash_set.end()) {
                return true;
            }
            hash_set.insert(num);
        }
        return false;
    }
};
