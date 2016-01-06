class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        if (strs.empty() == true) {
            return ans;
        }
        unordered_map<string, vector<string> > um;
        for (auto it = strs.begin(); it != strs.end(); ++it) {
            string tmp(*it);
            sort(tmp.begin(), tmp.end());
            cout << tmp << endl;
            auto umit = um.find(tmp);
            if (umit == um.end()) {
                vector<string> th(1, *it);
                um.insert(make_pair(tmp, th));
            } else {
                (*umit).second.push_back(*it);
            }
        }
        for (auto it = um.begin(); it != um.end(); ++it) {
            sort((*it).second.begin(), (*it).second.end());
            ans.push_back((*it).second);
        }
        return ans;
    }
};
