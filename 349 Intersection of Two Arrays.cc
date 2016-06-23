class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set_num1;
        set<int> set_num2;
        for (int num : nums1) {
            set_num1.insert(num);
        }
        for (int num : nums2) {
            set_num2.insert(num);
        }
        vector<int> ans;
        for (auto it = set_num1.begin(); it != set_num1.end(); ++it) {
            if (set_num2.find(*it) != set_num2.end()) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};
