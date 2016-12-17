class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0;
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            if (it == heaters.begin()) {
                ans = max(ans, (*it) - house);
            } else if (it == heaters.end()) {
                --it;
                ans = max(ans, house - (*it));
            } else {
                auto it_right = it;
                --it;
                ans = max(ans, min((*it_right) - house, house - (*it)));
            }
        }
        return ans;
    }
};
