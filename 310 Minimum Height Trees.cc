class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > graph(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto edge : edges) {
            graph.at(edge.first).push_back(edge.second);
            degree.at(edge.first) = degree.at(edge.first) + 1;
            graph.at(edge.second).push_back(edge.first);
            degree.at(edge.second) = degree.at(edge.second) + 1;
        }
        
        vector<int> one_degree;
        for (int i = 0; i < n; ++i) {
            if (degree.at(i) == 1) {
                one_degree.push_back(i);
            }
        }
        int left_nodes = n;
        while (left_nodes > 2) {
            vector<int> tmp_one_degree;
            for (int i : one_degree) {
                for (int j : graph.at(i)) {
                    if (degree.at(j) > 1) {
                        --degree.at(j);
                        if (degree.at(j) == 1) {
                            tmp_one_degree.push_back(j);
                        }
                    }
                }
                degree.at(i) = -1;  // has visited
            }
            left_nodes = left_nodes - one_degree.size();
            one_degree = tmp_one_degree;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (degree.at(i) >= 0) {  // haven't visited yet
                ans.push_back(i);
            }
        }
        return ans;
    }
};
