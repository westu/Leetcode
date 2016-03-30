class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> ans;
        if (static_cast<int>(s.size()) < 4 || static_cast<int>(s.size()) > 12) {
            return ans;
        }
        vector<int> pos_list;
        pos_list.push_back(0);
        dfs(pos_list, ans, s);
        return ans;
    }

private:
    void dfs(vector<int> &pos_list, vector<string> &ans, const string &s) {
        int l = static_cast<int>(pos_list.size());
        if (l == 4) {
            pos_list.push_back(static_cast<int>(s.length()));
            string tmp_ans = "";
            bool status(true);  // status of finding a valid IP
            for (int i = 0; i < l; ++i) {
                if (pos_list.at(i + 1) - pos_list.at(i) > 1 && s.at(pos_list.at(i)) == '0') {
                    // an IP which starts with '0' is invalid, e.g. 010
                    status = false;
                    break;
                }
                int tmp_ip = 0;
                for (int j = pos_list.at(i); j < pos_list.at(i + 1); ++j) {
                    tmp_ip = tmp_ip * 10 + s.at(j) - '0';
                    tmp_ans.push_back(s.at(j));
                }
                if (tmp_ip > 255) {
                    status = false;
                    break;
                } else if (i <= 2) {
                    tmp_ans.push_back('.');
                }
            }
            if (status == true) {
                ans.push_back(tmp_ans);
            }
            pos_list.pop_back();  // line 22
        } else {
            for (int i = pos_list.at(l - 1) + 1; i < static_cast<int>(s.size()); ++i) {
                pos_list.push_back(i);
                dfs(pos_list, ans, s);
                pos_list.pop_back();
            }
        }
    }
};
