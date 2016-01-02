class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> solu;
        dfs(ans, solu, candidates, -1, target, 0);
        return ans;
    }

private:
    void dfs(vector<vector<int> >& ans, vector<int>& solu,
             const vector<int>& candidates, int w, int target, int sum) {
        if (sum == target) {
            ans.push_back(solu);
            return;
        }
        for (int i = w + 1; i < static_cast<int>(candidates.size()); ++i)
            if ((i == (w + 1) || candidates[i] != candidates[i -1]) &&
                sum + candidates[i] <= target) {
                solu.push_back(candidates[i]);
                dfs(ans, solu, candidates, i, target, sum + candidates[i]);
                solu.pop_back();
        }
    }
};
