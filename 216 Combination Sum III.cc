class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> com;
        dfs(0, k, 0, n, com, ans, 0);
        return ans;
    }

private:
    void dfs(int hasNum, int k, int sum, int n, vector<int>& com,
        vector<vector<int> >& ans, int last_num) {
        if (hasNum == k) {
            if (sum == n) {
                ans.push_back(com);
            }
            return;
        }
        for (int i = last_num + 1; i <= 9; ++i) {
            com.push_back(i);
            dfs(hasNum + 1, k, sum + i, n, com, ans, i);
            com.pop_back();
        }
    }
};
