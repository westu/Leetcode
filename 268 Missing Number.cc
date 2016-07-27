class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        long long sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int l = static_cast<int>(nums.size());
        return (1 + l) * l / 2 - sum;
    }
};
