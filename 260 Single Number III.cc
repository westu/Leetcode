class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &nums) {
        int xor_result = 0;
        for (int n : nums) {
            xor_result ^= n;
        }
        int w = 0;
        while ((xor_result & 1) == 0) {
            ++w;
            xor_result >>= 1;
        }
        int sn1(0), sn2(0);
        for (int n : nums) {
            if (((n >> w) & 1) == 0) {
                sn1 ^= n;
            } else {
                sn2 ^= n;
            }
        }
        vector<int> ans;
        ans.push_back(sn1);
        ans.push_back(sn2);
        return ans;
    }
};
