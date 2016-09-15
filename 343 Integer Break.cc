class Solution {
public:
    int integerBreak(int n) {
        vector<int> max_product(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                max_product.at(j) = max(max_product.at(j), j);
                max_product.at(i - j) = max(max_product.at(i - j), i - j);
                max_product.at(i) = max(max_product.at(i),
                    max_product.at(j) * max_product.at(i - j));
            }
        }
        return max_product.at(n);
    }
};
