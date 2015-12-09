class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = static_cast<int>(height.size());
        if (len <= 1) {
            return 0;
        }
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
