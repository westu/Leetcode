class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        if (findNums.empty()) {
            return ans;
        }
        unordered_map<int, int> ans_map;
        stack<int> dec_list;
        for (int num : nums) {
            while (!dec_list.empty() && dec_list.top() < num) {
                ans_map.insert(make_pair(dec_list.top(), num));
                dec_list.pop();
            }
            dec_list.push(num);
        }
        while (!dec_list.empty()) {
            ans_map.insert(make_pair(dec_list.top(), -1));
            dec_list.pop();
        }
        for (int num : findNums) {
            ans.push_back(ans_map.find(num)->second);
        }
        return ans;
    }
};
