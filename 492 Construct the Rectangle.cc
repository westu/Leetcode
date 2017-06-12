class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        ans.push_back(area);
        ans.push_back(1);
        
        for (int i = 2; i <= (int)sqrt(area); ++i) {
            if (area / i * i == area) {
                ans.at(0) = max(area / i, i);
                ans.at(1) = min(area / i, i);
            }
        }
        return ans;
    }
};
