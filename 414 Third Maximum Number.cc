class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> max_num;
        for (int num : nums) {
            max_num.insert(num);
            if (max_num.size() > 3) {
                max_num.erase(max_num.begin());
            }
        }
        return max_num.size() == 3 ? *max_num.begin() : *max_num.rbegin();
    }
};
