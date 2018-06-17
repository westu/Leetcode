class Solution {
public:
    string crackSafe(int n, int k) {
        string str(n, '0');
        unordered_set<string> used;
        used.insert(str);
        for (int i = 1; i < (int)pow(k, n); ++i) {
            string next = str.substr(str.size() - n + 1, n - 1);
            for (int j = k - 1; j >= 0; --j) {
                if (used.find(next + to_string(j)) == used.end()) {
                    str += to_string(j);
                    used.insert(next + to_string(j));
                    break;
                }
            }
        }
        return str;
    }
};
