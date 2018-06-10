class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int l = static_cast<int>(nums.size());
        vector<vector<int>> sum(l + 1, vector<int>(l + 1, 0)),
            score1(l + 1, vector<int>(l + 1, 0)), score2(l + 1, vector<int>(l + 1, 0));
        for (int i = 1; i <= l; ++i) {
            for (int j = i; j <= l; ++j) {
                sum.at(i).at(j) = sum.at(i).at(j - 1) + nums.at(j - 1);
            }
        }
        
        for (int i = 1; i <= l; ++i) {  // length is 1
            score1[i][i] = nums.at(i - 1);
            score2[i][i] = nums.at(i - 1);
        }
        
        for (int i = 2; i <= l; ++i) {  // i is the length
            for (int j = 1; j <= l - i + 1; ++j) {
                score1[j][j + i - 1] = max(nums[j - 1] + sum[j + 1][j + i - 1] - score2[j + 1][j + i - 1],
                    nums[j + i - 2] + sum[j][j + i - 2] - score2[j][j + i - 2]);
                score2[j][j + i - 1] = max(nums[j - 1] + sum[j + 1][j + i - 1] - score1[j + 1][j + i - 1],
                    nums[j + i - 2] + sum[j][j + i - 2] - score1[j][j + i - 2]);
            }
        }
        
        return score1[1][l] >= (sum[1][l] - score1[1][l]);
    }
};
