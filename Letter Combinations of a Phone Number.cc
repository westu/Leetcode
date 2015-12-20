class Solution {
private:
    void dfs(const string& digits, int w, string sans, vector<string>& ans,
            const vector<string>& table) {
        if (w == static_cast<int>(digits.length())) {
            if (w > 0) {
                ans.push_back(sans);
            }
            return;
        }
        for (int i = 0; i < static_cast<int>(table[digits[w] - '0'].length()); i++) {
            dfs(digits, w + 1, sans + table[digits[w] - '0'][i], ans, table);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> table(10);
        int now_ch = 0;
        for (int i = 2; i <= 9; i++) {
            int now_num = (i == 7 || i == 9) ? 4 : 3;
            for (int j = 1; j <= now_num; j++) {
                now_ch++;
                table[i] += static_cast<char>('a' - 1 + now_ch);
            }
        }
        vector<string> ans;
        for (int i = 0; i < static_cast<int>(digits.length()); i++) {
            if (digits[i] < '2' || digits[i] > '9') {
                return ans;
            }
        }
        dfs(digits, 0, "", ans, table);
        return ans;
    }
};
