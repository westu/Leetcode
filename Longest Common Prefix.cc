class Solution {
private:
    bool is_prefix(vector<string>& strs, int w) {
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++) {
            if (w >= static_cast<int>((*it).size()) ||
                (*strs.begin())[w] != (*it)[w]) {
                    return false;
                }
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int w = 0;
        string ans;
        while (is_prefix(strs, w) == true) {
            ans += strs[0][w];
            w++;
        }
        return ans;
    }
};
