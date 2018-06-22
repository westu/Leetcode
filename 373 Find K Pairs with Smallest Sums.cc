class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> ans;
    if (k == 0 || nums1.empty() || nums2.empty()) {
      return ans;
    }
    
    multimap<int, pair<int, int>> min_heap;
    int len1 = static_cast<int>(nums1.size());
    int len2 = static_cast<int>(nums2.size());
    for (int i = 0; i < min(len1, k); ++i) {
      min_heap.insert(make_pair(nums1.at(i) + nums2.at(0), make_pair(i, 0)));
    }
    
    while (ans.size() < k && !min_heap.empty()) {
      auto min_pair = min_heap.begin();
      min_heap.erase(min_heap.begin());
      int pos1 = min_pair->second.first;
      int pos2 = min_pair->second.second;
      ans.push_back(make_pair(nums1.at(pos1), nums2.at(pos2)));
      if (pos2 + 1 < len2) {
        min_heap.insert(make_pair(nums1.at(pos1) + nums2.at(pos2 + 1), make_pair(pos1, pos2 + 1)));
      }
    }
    
    return ans;
  }
};

// class Solution2nd {
//  public:
//   vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//     vector<pair<int, int>> pairs;
//     if (nums1.empty() || nums2.empty()) {
//       return pairs;
//     }
//     multimap<int, pair<int, int>> min_heap;
//     for (int i = 0; i < min(k, static_cast<int>(nums2.size())); ++i) {
//       min_heap.insert(make_pair(nums1.at(0) + nums2.at(i), make_pair(nums1.at(0), nums2.at(i))));
//     }
//     for (int i = 1; i < static_cast<int>(nums1.size()); ++i) {
//       for (int j = 0; j < min(k, static_cast<int>(nums2.size())); ++j) {
//         if (min_heap.size() == k && nums1.at(i) + nums2.at(j) >= min_heap.rbegin()->first) {
//           break;
//         }
//         if (min_heap.size() == k) {
//           auto it = min_heap.end();
//           --it;
//           min_heap.erase(it);
//         }
//         min_heap.insert(make_pair(nums1.at(i) + nums2.at(j), make_pair(nums1.at(i), nums2.at(j))));
//       }
//     }
//     for (auto it : min_heap) {
//       pairs.push_back(it.second);
//     }
//     return pairs;
//   }
// };
