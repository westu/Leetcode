class Solution {
public:
    string addStrings(string num1, string num2) {
        int ans_len = max(num1.size(), num2.size()) + 1;
        string ans(ans_len, '0');
        int has_ten = 0;
        for (int i = ans_len - 1; i >= 0; --i) {
            int num1_pos = num1.size() - (ans.size() - i);
            int num2_pos = num2.size() - (ans.size() - i);
            if (num1_pos >= 0 && num2_pos >= 0) {
                ans[i] = has_ten + num1[num1_pos] - '0' + num2[num2_pos] - '0';
            } else if (num1_pos >= 0) {
                ans[i] = has_ten + num1[num1_pos] - '0';
            } else if (num2_pos >= 0) {
                ans[i] = has_ten + num2[num2_pos] - '0';
            } else {
                ans[i] = has_ten;
            }
            has_ten = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        
        for (char &c : ans) {
            c = c + '0';
        }
        if (ans[0] != '0') {
            return ans;
        } else {
            return ans.substr(1, ans.size() - 1);
        }
    }
};
