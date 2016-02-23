class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while (i < static_cast<int>(words.size())) {
            int tmp_l = static_cast<int>(words.at(i).size());
            int p(i + 1), words_len(tmp_l), line_len(tmp_l);
            while (p < static_cast<int>(words.size())) {  // chosen part: [i..p)
                tmp_l = static_cast<int>(words.at(p).size());
                if (line_len + 1 + tmp_l <= maxWidth) {
                    ++p;
                    line_len += 1 + tmp_l;
                    words_len += tmp_l;
                } else {
                    break;
                }
            }
            string tmp_ans;
            tmp_ans = words.at(i);  // puts the first word
            if (p - i == 1) {
                for (int j = static_cast<int>(words.at(i).length()) + 1; j <= maxWidth; ++j) {
                    tmp_ans.push_back(' ');
                }
            } else {
                if (p == static_cast<int>(words.size())) {  // last line of text
                    for (int j = i + 1; j < p; ++j) {
                        tmp_ans += ' ' + words.at(j);
                    }
                    for (int j = static_cast<int>(tmp_ans.size()) + 1; j <= maxWidth; ++j) {
                        tmp_ans.push_back(' ');
                    }
                } else {
                    int blank_len = (maxWidth - words_len) / (p - i - 1);
                    int long_blank_num = (maxWidth - words_len) % (p - i - 1);
                    for (int j = 0; j < long_blank_num; ++j) {
                        for (int k = 0; k < blank_len + 1; ++k) {
                            tmp_ans.push_back(' ');
                        }
                        tmp_ans += words.at(i + j + 1);
                    }
                    for (int j = long_blank_num; j < p - i - 1; ++j) {
                        for (int k = 0; k < blank_len; ++k) {
                            tmp_ans.push_back(' ');
                        }
                        tmp_ans += words.at(i + j + 1);
                    }
                }
            }
            ans.push_back(tmp_ans);
            i = p;
        }
        return ans;
    }
};
