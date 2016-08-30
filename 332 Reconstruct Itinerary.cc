bool cmp(const pair<string, string> &p1, const pair<string, string> &p2) {
    return p1.second < p2.second;
}

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        ans.push_back("JFK");
        if (tickets.empty()) {
            return ans;
        }
        
        sort(tickets.begin(), tickets.end(), cmp);
        vector<bool> used(static_cast<int>(tickets.size()), false);
        dfs(tickets, used, ans);
        return ans;
    }

private:
    bool dfs(const vector<pair<string, string>>& tickets,
        vector<bool> &used, vector<string> &ans) {
        if (ans.size() == tickets.size() + 1) {
            return true;
        }
            
        int l = static_cast<int>(tickets.size());
        for (int i = 0; i < l; ++i) {
            if (!used[i] && tickets.at(i).first == ans.back()) {
                used[i] = true;
                ans.push_back(tickets.at(i).second);
                if (dfs(tickets, used, ans)) {
                    return true;
                }
                used[i] = false;
                ans.pop_back();
            }
        }
        return false;
    }
};
