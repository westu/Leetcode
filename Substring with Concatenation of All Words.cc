class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() == true) {
            return ans;
        }
        if (words[0] == "") {
            for (int i = 0; i <= static_cast<int>(s.size()); i++) {
                ans.push_back(i);
            }
            return ans;
        }
        unordered_map<string, int> words_list;
        for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
            unordered_map<string, int>::iterator wit = words_list.find(*it);
            if (wit == words_list.end()) {
                words_list.insert(make_pair(*it, 1));
            } else {
                (*wit).second = (*wit).second + 1;
            }
        }
        int sub_len = static_cast<int>(words[0].size()) *
                      static_cast<int>(words.size());
        for (int i = 0; i <= static_cast<int>(s.size()) - sub_len; i++) {
            if (check_sub_str(s, i, i + sub_len, words, words_list) == true) {
                ans.push_back(i);
            }
        }
        return ans;
    }

private:
    bool check_sub_str(const string& s, int start_pos, int end_pos,
                       const vector<string>& words,
                       const unordered_map<string, int>& words_list) {
        unordered_map<string, int> tmp_count;
        for (int i = start_pos; i < end_pos; i += static_cast<int>(words[0].size())) {
            string tmp_str;
            for (int j = 0; j < static_cast<int>(words[0].size()); j++) {
                tmp_str.push_back(s[i + j]);
            }
            unordered_map<string, int>::const_iterator list_it = words_list.find(tmp_str);
            if (list_it == words_list.end()) {
                return false;
            }
            unordered_map<string, int>::iterator count_it = tmp_count.find(tmp_str);
            if (count_it == tmp_count.end()) {
                tmp_count.insert(make_pair(tmp_str, 1));
            } else {
                (*count_it).second = (*count_it).second + 1;
                if ((*count_it).second > (*list_it).second) {
                    return false;
                }
            }
        }
        return true;
    }
};
