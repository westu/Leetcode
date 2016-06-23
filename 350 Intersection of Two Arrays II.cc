class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        auto i = nums1.begin();
        auto j = nums2.begin();
        while (i != nums1.end() && j != nums2.end()) {
            if (*i == *j) {
                ans.push_back(*i);
                ++i;
                ++j;
            } else if (*i < *j) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
