class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = static_cast<int>(citations.size());
        vector<int> counter(l + 1, 0);
        for (int c : citations) {
            if (c > l) {
                counter.at(l) = counter.at(l) + 1;
            } else {
                counter.at(c) = counter.at(c) + 1;
            }
        }
        int count = 0;
        for (int h = l; h >=0; --h) {
            if (count <= h && h <= count + counter.at(h)) {
                return h;
            }
            count = count + counter.at(h);
        }
        return 0;
    }
};
