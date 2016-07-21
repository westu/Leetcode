class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> hash_table;
        for (char c : s) {
            auto it = hash_table.find(c);
            if (it == hash_table.end()) {
                hash_table.insert(make_pair(c, 1));
            } else {
                it->second = it->second + 1;
            }
        }
        for (char c : t) {
            auto it = hash_table.find(c);
            if (it == hash_table.end()) {
                return false;
            } else {
                it->second = it->second - 1;
                if (it->second == 0) {
                    hash_table.erase(it);
                }
            }
        }
        return hash_table.size() == 0;
    }
};
