class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        unordered_map<int, int> counter;
        for (int num : nums) {
            auto it = counter.find(num);
            if (it == counter.end()) {
                counter.insert(make_pair(num, 1));
            } else {
                ++(*it).second;
            }
        }
        multimap<int, int> heap;
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            if (heap.size() < k) {
                heap.insert(make_pair(it->second, it->first));
            } else {
                if (it->second > heap.begin()->first) {
                    heap.erase(heap.begin());
                    heap.insert(make_pair(it->second, it->first));
                }
            }
        }
        for (auto it = heap.rbegin(); it != heap.rend(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
