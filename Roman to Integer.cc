class Solution {
private:
    int find_ch(char ch, char c[5], int j) {
        for (int i = 1; i <= j; i++) {
            if (ch == c[i]) {
                return i;
            }
        }
        return 0;
    }

public:
    int romanToInt(string s) {
        char c10[5], c5[10];
        c10[0] = '#';
        c10[1] = 'M';
        c10[2] = 'C';
        c10[3] = 'X';
        c10[4] = 'I';
        c5[0] = '#';
        c5[1] = 'D';
        c5[2] = 'L';
        c5[3] = 'V';
        int ans = 0;
        int len = static_cast<int>(s.size());
        int i = 0;
        while (i < len) {
            int j = find_ch(s[i], c10, 4);
            if (j > 0) {
                if (i + 1 < len) {
                    if (s[i + 1] == c10[j - 1]) {
                        ans += 9 * pow(10, 4 - j);
                        i += 2;
                    } else if (s[i + 1] == c5[j - 1]) {
                        ans += 4 * pow(10, 4 - j);
                        i += 2;
                    } else {
                        ans += 1 * pow(10, 4 - j);
                        i += 1;
                    }
                } else {
                    ans += 1 * pow(10, 4 - j);
                    i += 1;
                }
            } else {
                j = find_ch(s[i], c5, 3);
                ans += 5 * pow(10, 3 - j);
                i += 1;
            }
        }
        return ans;
    }
};
