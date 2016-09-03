class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = static_cast<int>(nums.size());
        k = k % l;
        reverse(nums, 0, l);
        reverse(nums, 0, k);
        reverse(nums, k, l);
    }

private:
    void reverse(vector<int> &nums, int l, int r) {
        while (l < r - 1) {
            int tmp = nums.at(l);
            nums.at(l) = nums.at(r - 1);
            nums.at(r - 1) = tmp;
            ++l;
            --r;
        }
    }
};
