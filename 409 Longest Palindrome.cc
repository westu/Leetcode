class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash_map;
        for (char c : s) {
            auto it = hash_map.find(c);
            if (it == hash_map.end()) {
                hash_map.insert(make_pair(c, 1));
            } else {
                it->second = it->second + 1;
            }
        }
        
        int ans(0), odd_met(false);
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
            ans += it->second / 2 * 2;
            if (!odd_met && (it->second & 1 == 1)) {
                ++ans;
                odd_met = true;
            }
        }
        return ans;
    }
};
