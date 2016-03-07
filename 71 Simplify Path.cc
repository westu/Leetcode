class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        vector<string> dirs;
        for (size_t i = 0; i < path.size();) {
            ++i;
            size_t j = path.find('/', i);
            string sub_dir = path.substr(i, j - i);  // regardless "/" on left and right sides
            if (sub_dir.empty() == false && sub_dir != ".") {
                if (sub_dir == "..") {
                    if (dirs.empty() == false) {
                        dirs.pop_back();
                    }
                } else {
                    dirs.push_back(sub_dir);
                }
            }
            i = j;
        }
        string ans;
        if (dirs.empty() == true) {
            ans = "/";
        } else {
            for (auto it = dirs.begin(); it != dirs.end(); ++it) {
                ans += "/" + (*it);
            }
        }
        return ans;
    }
};
