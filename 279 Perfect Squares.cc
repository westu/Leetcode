class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= static_cast<int>(sqrt(n)); ++i) {
            squares.push_back(i * i);
        }
        vector<int> perfect_sq;
        perfect_sq.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int this_num = i;
            for (int s : squares) {
                if (s > i) {
                    break;
                }
                this_num = min(this_num, 1 + perfect_sq.at(i - s));
            }
            perfect_sq.push_back(this_num);
        }
        return perfect_sq.back();
    }
};
