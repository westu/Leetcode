class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &height) {
        int len = static_cast<int>(height.size());
        if (len <= 2) {
            return 0;
        }
        int max_height = height[0];
        int max_height_index;
        for (int i = 0; i < len; ++i) {
            if (height[i] >= max_height) {
                max_height = height[i];
                max_height_index = i;
            }
        }
        int ans = 0;
        // from left to right
        int current_h = height[0];
        for (int i = 1; i <= max_height_index; ++i) {
            if (height[i] < current_h) {
                ans += current_h - height[i];
            } else {
                current_h = height[i];
            }
        }
        // from right to left
        current_h = height[len - 1];
        for (int i = len - 1; i >= max_height_index; --i) {
            if (height[i] < current_h) {
                ans += current_h - height[i];
            } else {
                current_h = height[i];
            }
        }
        return ans;
    }
};
