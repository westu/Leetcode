class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty() == true) {
            return 0;
        }
        unordered_map<char, int> p;
        // record the last place of current character's appearance, false or not in map means it's the first time of this charactor
        int subscript_f = 0;
        int ans = 0;
        
        vector<int> f;
        // f[i] records the longest substring whithout repeating characters which ends with s[i - 1]
        f.push_back(0); // f[0] = 0
        
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            subscript_f += 1;
            if (p.find(*it) == p.end()) {
                f.push_back(f[subscript_f - 1] + 1);
            }
            else {
                f.push_back(min(f[subscript_f - 1] + 1, subscript_f - p[*it]));
            }
            p[*it] = subscript_f;
            ans = max(ans, f[subscript_f]);
        }
        return ans;
    }
};

/* // this one need less memory than the code above
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty() == true) {
            return 0;
        }
        unordered_map<char, int> p; // record the last place of current character's appearance, false or not in map means it's the first time of this charactor
        int subscript_f = 0;
        int ans = 0;
        int last_char_sublen = 0; // in fact, it just need to record two values of array f above
        int current_char_sublen;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            subscript_f += 1;
            if (p.find(*it) == p.end()) {
                current_char_sublen = last_char_sublen + 1;
            }
            else {
                current_char_sublen = min(last_char_sublen + 1, subscript_f - p[*it]);
            }
            p[*it] = subscript_f;
            ans = max(ans, current_char_sublen);
            last_char_sublen = current_char_sublen;
        }
        return ans;
    }
};*/
