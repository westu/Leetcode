class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() == true || num2.empty() ==true) {
            return "";
        }
        int len1 = static_cast<int>(num1.size());
        int len2 = static_cast<int>(num2.size());
        int len3 = len1 + len2;
        vector<int> num3(len3, 0);
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                num3[i + j] += (num1[len1 - 1 - i] - '0') * (num2[len2 - 1- j] - '0');
            }
        }
        for (int i = 0; i < len3; ++i) {
            if (num3[i] > 9) {
                num3[i + 1] += num3[i] / 10;
                num3[i] = num3[i] % 10;
            }
        }
        int real_len = len3 - 1;
        while (num3[real_len] == 0 && real_len >= 0) {
            --real_len;
        }
        if (real_len < 0) {
            return "0";
        }
        string ans;
        for (int i = real_len; i >=0; --i) {
            ans.push_back(num3[i] + '0');
        }
        return ans;
    }
};
