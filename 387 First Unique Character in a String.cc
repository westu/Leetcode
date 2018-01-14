class Solution {
public:
    /*
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        if (s.empty()) {
            return -1;
        }
        unordered_map<char, int> char_count;
        for (char c : s) {
            auto it = char_count.find(c);
            if (it == char_count.end()) {
                char_count.insert(make_pair(c, 1));
            } else {
                it->second = it->second + 1;
            }
        }
        
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            auto it = char_count.find(s.at(i));
            if (it->second == 1) {
                return i;
            }
        }
        return -1;
    }
};
