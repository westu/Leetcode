class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        int l = static_cast<int>(A.size());
        int prev_sum(0), sum(0);
        for (int i = 0; i < l; ++i) {
            prev_sum += A.at(i) * i;
            sum += A.at(i);
        }
        
        int ans(prev_sum);
        for (int i = 1; i < l; ++i) {
            int this_sum = prev_sum + sum - A.at(l - i) * l;
            ans = max(ans, this_sum);
            prev_sum = this_sum;
        }
        return ans;
    }
};
