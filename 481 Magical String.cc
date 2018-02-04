class Solution {
public:
    int magicalString(int n) {
        vector<int> s;
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);
        int i(2), j(3);
        while (j < n) {
            for (int k = 1; k <= s.at(i); ++k) {
                s.push_back(3 - s.at(j - 1));
            }
            j += s.at(i);
            ++i;
        }
        
        return count(s.begin(), s.begin() + n, 1);
    }
};
