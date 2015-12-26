class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &nums, int val) {
        int len = static_cast<int>(nums.size());
        if (len == 0) {
            return 0;
        }
        int l = -1;
        int r = len - 1;
        while (l < r) {
            while (l < r && nums[l + 1] != val) {
                l++;
            }
            if (l < r) {
                nums[l + 1] = nums[r];
                r--;
            }
        }
        return l + 1;
    }
};
