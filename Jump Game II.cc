class Solution {
public:
    int jump(vector<int>& nums) {
        int l = static_cast<int>(nums.size());
        if (l == 1) {
            return 0;
        }
        vector<int> record(l, -1);
        record[0] = 0;
        int reach = 0;
        for (int i = 0; i < l; ++i) {
            int jump_pos = i + nums[i];
            if (jump_pos >= l - 1) {
                record[l - 1] = record[i] + 1;
                break;
            } else if (jump_pos > reach) {
                for (int j = reach + 1; j <= jump_pos; ++j) {
                    record[j] = record[i] + 1;
                }
                reach = jump_pos;
            }
        }
        return record[l - 1];
    }
};
