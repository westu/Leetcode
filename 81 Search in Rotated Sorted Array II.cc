class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty() == true) {
            return false;
        }
        int l = static_cast<int>(nums.size());
        if (l == 1) {
            return nums.at(0) == target;
        }
        int s(0), t(l);
        while (s < t) {
            int mid = s + (t - s) / 2;
            if (nums.at(mid) == target) {
                return true;
            }
            int part;  // 0: is in the left part; 1: in the right
            if (nums.at(s) != nums.at(t - 1) || nums.at(mid) != nums.at(s)) {
                part = nums.at(mid) >= nums.at(s) ? 0 : 1;
            } else {  // nums.at(mid) == nums.at(s) == nums.at(t)
                int i = mid;
                while (i < t && nums.at(i) == nums.at(mid)) {
                    ++i;
                }
                part = i == t ? 1 : 0;
            }
            if (part == 0) {  // mid is in the left part
                if (target >= nums.at(s) && target < nums.at(mid)) {
                    t = mid;
                } else {
                    s = mid + 1;
                }
            } else {
                if (target > nums.at(mid) && target <= nums.at(t - 1)) {
                    s = mid + 1;
                } else {
                    t = mid;
                }
            }
        }
        return false;
    }
};
