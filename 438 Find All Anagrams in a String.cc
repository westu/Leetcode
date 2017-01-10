class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.empty() || s.size() < p.size()) {
            return ans;
        }
        unordered_map<char, int> counter;
        unordered_map<char, int> p_counter;
        int window_size = static_cast<int>(p.size());
        for (int i = 0; i < window_size - 1; ++i) {
            ++counter[s.at(i)];
        }
        for (char c : p) {
            ++p_counter[c];
        }
        for (int i = 0; i <= s.size() - window_size; ++i) {
            ++counter[s.at(i + window_size - 1)];
            if (is_same(counter, p_counter)) {
                ans.push_back(i);
            }
            --counter[s.at(i)];
        }
        return ans;
    }

private:
    bool is_same(const unordered_map<char, int> &counter, const unordered_map<char, int> &p_counter) {
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            auto p_it = p_counter.find(it->first);
            if (p_it != p_counter.end() &&  p_it->second != it->second) {
                return false;
            }
            if (p_it == p_counter.end() && it->second != 0) {
                return false;
            }
        }
        return true;
    }
};
