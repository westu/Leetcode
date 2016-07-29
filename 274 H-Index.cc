class Solution {
public:
    int hIndex(vector<int>& citations) {
        citations.push_back(-1);
        sort(citations.begin(), citations.end());
        int l = static_cast<int>(citations.size());
        for (int i = l - 1; i > 0; --i) {
            int h = l - i;
            if (citations.at(i) >= h && citations.at(i - 1) <= h) {
                return h;
            }
        }
        return 0;
    }
};
