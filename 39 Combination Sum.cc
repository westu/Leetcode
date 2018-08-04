class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> solu;
        dfs(ans, solu, candidates, 0, target, 0);
        return ans;
    }

private:
    void dfs(vector<vector<int> >& ans, vector<int>& solu,
             const vector<int>& candidates, int w, int target, int sum) {
        if (sum == target) {
            ans.push_back(solu);
            return;
        }
        for (int i = w; i < static_cast<int>(candidates.size()); ++i)
            if (sum + candidates[i] <= target) {
                solu.push_back(candidates[i]);
                dfs(ans, solu, candidates, i, target, sum + candidates[i]);
                solu.pop_back();
        }
    }
};
