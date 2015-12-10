class Solution {
private:
    int get_each_value(int& num, int w) {
        int re = num / w;
        num -= w * re;
        return re;
    }
public:
    string intToRoman(int num) {
        int n[5];  // 1 <= num <= 3999
        int w = 1000;
        for (int i = 1; i <= 4; i++) {
            n[i] = get_each_value(num, w);
            w /= 10;
        }
        string ans;
        for (int i = 1; i <= n[1]; i++) {  // 1000
            ans += 'M';
        }
        char ch_list1[5], ch_list2[5];
        ch_list1[1] = 'M';
        ch_list1[2] = 'C';
        ch_list2[2] = 'D';
        ch_list1[3] = 'X';
        ch_list2[3] = 'L';
        ch_list1[4] = 'I';
        ch_list2[4] = 'V';
        for (int i = 2; i <= 4; i++) {  // 100 10 1
            if (n[i] == 9) {
                ans += ch_list1[i];
                ans += ch_list1[i - 1];
            } else if (n[i] == 4) {
                ans += ch_list1[i];
                ans += ch_list2[i];
            } else {
                if (n[i] >= 5) {
                    ans += ch_list2[i];
                }
                for (int j = 1; j <= (n[i] % 5); j++) {
                    ans += ch_list1[i];
                }
            }
        }
        return ans;
    }
};
