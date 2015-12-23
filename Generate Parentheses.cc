class Solution {
private:
    void dfs(int left_num, int right_num, string s, vector<string>& ans, int stack_num) {
        if (left_num == 0 && right_num == 0) {
            ans.push_back(s);
            return ;
        }
        if (left_num > 0) {
            dfs(left_num - 1, right_num, s + '(', ans, stack_num + 1);
        }
        if (right_num > 0 && stack_num > 0) {
            dfs(left_num, right_num - 1, s + ')', ans, stack_num - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // stack<char> st;
        int stack_num = 0;  // we don't need a real stack, just need to record
        // the number of '('
        dfs(n, n, "", ans, stack_num);
        return ans;
    }
};
