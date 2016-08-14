class Solution {
public:
    int bulbSwitch(int n) {
        long long m = static_cast<long long>(n);
        long long i = 1;
        int ans = 0;
        while (i * i <= m) {
            ++ans;
            ++i;
        }
        return ans;
    }
};
