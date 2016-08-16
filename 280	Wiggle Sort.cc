class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 1; ++i) {
            if ((i & 1) == 1 && nums.at(i) < nums.at(i + 1)) {
                swap(nums.at(i), nums.at(i + 1));
            } else if ((i & 1) == 0 && nums.at(i) > nums.at(i + 1)) {
                swap(nums.at(i), nums.at(i + 1));
            }
        }
    }
};
