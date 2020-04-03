class Solution {
public:
    int findLucky(vector<int>& arr) {
        if (arr.empty()) {
            return -1;
        }
        vector<int> num_counter(501, 0);
        for (int num : arr) {
            num_counter.at(num) = num_counter.at(num) + 1;
        }
        for (int i = 500; i > 0; --i) {
            if (num_counter.at(i) == i) {
                return i;
            }
        }
        return -1;
    }
};
