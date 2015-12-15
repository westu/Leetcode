class Solution {
private:
    bool not_equal(const vector<vector<int>> ans, 
        const vector<int> tmp) {
        if (ans.empty() == true) {
            return true;
        }
        //vector<vector<int>>::reverse_iterator it = ans.rbegin();
        if ((*ans.rbegin())[0] != tmp[0] || (*ans.rbegin())[1] != tmp[1] || (*ans.rbegin())[2] != tmp[2]) {
            return true;
        } else {
            return false;
        }
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        vector<vector<int>> ans;
        if (size < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> um;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++) {
                unordered_map<int, vector<pair<int, int>>>::iterator it
                    = um.find(nums[i] + nums[j]);
                if (it == um.end()) {
                    vector<pair<int, int>> tmp;
                    tmp.push_back(make_pair(i, j));
                    um.insert(make_pair(nums[i] + nums[j], tmp));
                } else if (nums[it->second.rbegin()->first] != nums[i]) {  // avoid repeated elements
                   it->second.push_back(make_pair(i, j));
                }
            }
        for (int i = 2; i < size; i++) {
          if (i == (size - 1) || nums[i] < nums[i + 1]) {
              unordered_map<int, vector<pair<int, int>>>::iterator it
                  = um.find(-nums[i]);
              if (it != um.end()) {
                  int this_size = static_cast<int>(it->second.size());
                  for (int j = 0; j < this_size; j++) {
                      vector<int> tmp;
                      tmp.push_back(nums[it->second[j].first]);
                      tmp.push_back(nums[it->second[j].second]);
                      tmp.push_back(nums[i]);
                      if (i > it->second[j].second && not_equal(ans, tmp)) {
                          ans.push_back(tmp);
                      }
                  }
              }
          }
        }
        return ans;
    }
};
