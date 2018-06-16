/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        if (wordlist.empty()) {
            return;
        }
        for (int k = 0; k < 10; ++k) {
            int len = static_cast<int>(wordlist.size());
            vector<int> total_diff_num(len, 0);
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    if (word_dis(wordlist.at(i), wordlist.at(j)) == 6) {
                        ++total_diff_num.at(i);
                    }
                }
            }
            pair<string, int> min_diff = make_pair(*wordlist.begin(), len);
            for (int i = 0; i < len; ++i) {
                if (total_diff_num.at(i) < min_diff.second) {
                    min_diff = make_pair(wordlist.at(i), total_diff_num.at(i));
                }
            }
            int dis = master.guess(min_diff.first);
            if (dis == 6) {
                return;
            }
            vector<string> wordlist2;
            for (string word : wordlist) {
                if (word_dis(word, min_diff.first) == (6 - dis)) {
                    wordlist2.push_back(word);
                }
            }
            wordlist = wordlist2;
        }
    }

private:
    int word_dis(const string &s1, const string &s2) {
        int dis = 0;
        for (int i = 0; i < 6; ++i) {
            if (s1.at(i) != s2.at(i)) {
                ++dis;
            }
        }
        return dis;
    }
};
