class Solution {
public:
    string getHint(string secret, string guess) {
        int a(0), b(0);
        unordered_map<char, int> hash_table;
        for (int i = 0; i < static_cast<int>(secret.size()); ++i) {
            if (secret.at(i) != guess.at(i)) {
                auto it = hash_table.find(secret.at(i));
                if (it == hash_table.end()) {
                    hash_table.insert(make_pair(secret.at(i), 1));
                } else {
                    ++it->second;
                }
            }
        }
        
        for (int i = 0; i < static_cast<int>(secret.size()); ++i) {
            if (secret.at(i) == guess.at(i)) {
                ++a;
            } else {
                auto it = hash_table.find(guess.at(i));
                if (it != hash_table.end()) {
                    ++b;
                    --it->second;
                    if (it->second == 0) {
                        hash_table.erase(it);
                    }
                }
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
