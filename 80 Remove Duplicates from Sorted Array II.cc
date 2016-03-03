class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int l = static_cast<int>(nums.size());
        if (l <= 2) {
            return l;
        }
        int i(0), twice_check(1);
        for (int j = 1; j < l; ++j) {
            if (nums.at(j) > nums.at(i)) {
                nums.at(++i) = nums.at(j);
                twice_check = 1;
            } else if (twice_check == 1) {  // nums.at(j) must equals nums.at(i)
                nums.at(++i) = nums.at(j);
                twice_check = 2;
            }
        }
        return i + 1;  // return length, not index
    }
};
