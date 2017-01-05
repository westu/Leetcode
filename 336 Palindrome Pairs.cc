class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int word_num = static_cast<int>(words.size());
        vector<vector<int> > ans;
        if (word_num == 0) {
            return ans;
        }
        
        unordered_map<string, int> word_hashmap;
        unordered_map<string, int> reverse_word_hashmap;
        unordered_set<long long> ans_pair_hash;
        for (int i = 0; i < word_num; ++i) {
            word_hashmap.insert(make_pair(words.at(i), i));
            string tmp_str = words.at(i);
            reverse(tmp_str.begin(), tmp_str.end());
            reverse_word_hashmap.insert(make_pair(tmp_str, i));
        }
        
        vector<int> single_ans = vector<int>(2);
        for (int i = 0; i < word_num; ++i) {
            int word_len = static_cast<int>(words[i].size());
            
            if (word_len == 0) {
                for (int j = 0; j < word_num; ++j) {
                    if (i != j && is_palindrome(words.at(j), 0, words.at(j).size())) {
                        single_ans.at(0) = i;
                        single_ans.at(1) = j;
                        ans.push_back(single_ans);
                        
                        if (words.at(j) != "") {
                            single_ans.at(0) = j;
                            single_ans.at(1) = i;
                            ans.push_back(single_ans);
                        }
                    }
                }
                continue;
            }
            
            string tmp_str = "";
            for (int j = 0; j < word_len; ++j) {
                tmp_str.push_back(words.at(i).at(j));
                if (is_palindrome(words[i], j + 1, word_len)) {
                    auto it = reverse_word_hashmap.find(tmp_str);
                    if (it != reverse_word_hashmap.end() && it->second != i) {
                        long long tmp_ans = i * word_num + it->second;
                        if (ans_pair_hash.find(tmp_ans) == ans_pair_hash.end()) {
                            // avoid an answer(which is a pair) appears more than onec in answer set, like "aaaaa" and "aa"
                            single_ans.at(0) = i;
                            single_ans.at(1) = it->second;
                            ans.push_back(single_ans);
                            ans_pair_hash.insert(tmp_ans);
                        }
                    }
                }
            }
            
            tmp_str = "";
            for (int j = word_len - 1; j >= 0; --j) {
                tmp_str.push_back(words.at(i).at(j));
                if (is_palindrome(words.at(i), 0, j)) {
                    auto it = word_hashmap.find(tmp_str);
                    if (it != word_hashmap.end() && it->second != i) {
                        long long tmp_ans = it->second * word_num + i;
                        if (ans_pair_hash.find(tmp_ans) == ans_pair_hash.end()) {
                            single_ans.at(0) = it->second;
                            single_ans.at(1) = i;
                            ans.push_back(single_ans);
                            ans_pair_hash.insert(tmp_ans);
                        }
                    }
                }
            }
        }
        
        return ans;
    }

private:
    bool is_palindrome(const string &str, int p, int q) {
        for (int i = p, j = q - 1; i < j; ++i, --j) {
            if (str.at(i) != str.at(j)) {
                return false;
            }
        }
        return true;
    }
};
