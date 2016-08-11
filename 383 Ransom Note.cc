class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash_map;
        for (char c : magazine) {
            auto it = hash_map.find(c);
            if (it == hash_map.end()) {
                hash_map.insert(make_pair(c, 1));
            } else {
                ++(it->second);
            }
        }
        
        for (char c : ransomNote) {
            auto it = hash_map.find(c);
            if (it == hash_map.end()) {
                return false;
            } else {
                --(it->second);
                if (it->second == 0) {
                    hash_map.erase(it);
                }
            }
        }
        return true;
    }
};
