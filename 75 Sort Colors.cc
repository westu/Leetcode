class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        if (nums.empty() == true) {
            return;
        }
        int index0(0), index2(static_cast<int>(nums.size()) - 1);
        for (int i = 0; i <= index2;) {
            if (nums.at(i) == 0) {
                swap(nums, i, index0);
                ++index0;
                ++i;
            } else if (nums.at(i) == 2) {
                swap(nums, i, index2);
                --index2;
            } else {
                ++i;
            }
        }
    }

private:
    void swap(vector<int> &nums, int index1, int index2) {
        int tmp = nums.at(index1);
        nums.at(index1) = nums.at(index2);
        nums.at(index2) = tmp;
    }
};
