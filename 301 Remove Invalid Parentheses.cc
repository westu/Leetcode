class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        while (!s.empty() && s.back() == '(') {
            s.pop_back();
        }
        
        queue<string> bfs_queue;
        unordered_set<string> hash_table;
        bfs_queue.push(s);
        hash_table.insert(s);
        while (!bfs_queue.empty()) {
            string s2 = bfs_queue.front();
            bfs_queue.pop();
            if (is_valid(s2)) {
                ans.push_back(s2);
                continue;
            }
            
            for (int i = 0; i < static_cast<int>(s2.size()); ++i) {
                if ((ans.empty() || s2.size() > ans.at(0).size()) &&
                        (s2.at(i) == '(' || s2.at(i) == ')')) {
                    string s3 = s2.substr(0, i) + s2.substr(i + 1);
                    if (hash_table.find(s3) == hash_table.end()) {
                        bfs_queue.push(s3);
                        hash_table.insert(s3);
                    }
                }
            }
        }
        return ans;        
    }

private:
    bool is_valid(const string& s) {
        int left_par_num = 0;
        for (char c : s) {
            if (c == '(') {
                ++left_par_num;
            } else if (c == ')') {
                --left_par_num;
                if (left_par_num < 0) {
                    return false;
                }
            }
        }
        return left_par_num == 0;
    }
};
