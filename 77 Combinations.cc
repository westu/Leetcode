class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> com_stack;
        dfs(ans, 1, n, k, com_stack);
        return ans;
    }

private:
    void dfs(vector<vector<int> > &ans, int start, int n, int k, vector<int> &com_stack) {
        int l = static_cast<int>(com_stack.size());
        if (l == k) {
            ans.push_back(com_stack);
            return;
        }
        if (k - l > n - start + 1) {  // choose from [start, n]
            return;
        }
        for (int i = start; i <= (n - (k - l - 1)); ++i) {
            com_stack.push_back(i);
            dfs(ans, i + 1, n, k, com_stack);
            com_stack.pop_back();
        }
    }
};
