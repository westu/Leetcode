class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> nums;
        return isAdd(num, 0, 0, nums, false);
    }

private:
    bool isAdd(const string& num, int pos, long long current_num, vector<long long>& nums, bool prev_has_combined) {
        int l = static_cast<int>(num.size());
        int n = static_cast<int>(nums.size());
        
        if (pos == l) {
            if (n >= 3 && prev_has_combined == false) {
                return true;
            } else {
                return false;
            }
        }
        
        if (prev_has_combined && current_num == 0) {  // leading zeros
            return false;
        }
        
        current_num = current_num * 10 + num.at(pos) - '0';
        if (n < 2 || current_num == nums.at(n - 1) + nums.at(n - 2)) {
            nums.push_back(current_num);
            if (isAdd(num, pos + 1, 0, nums, false)) {
                return true;
            }
            nums.pop_back();
        }
        if (n < 2 || current_num < nums.at(n - 1) + nums.at(n - 2)) {
            if (isAdd(num, pos + 1, current_num, nums, true)) {
                return true;
            }
        }
        
        return false;
    }
};
