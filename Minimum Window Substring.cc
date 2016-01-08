class Solution {
 public:
  string minWindow(string s, string t) {
    int l1 = static_cast<int>(s.size());
    int l2 = static_cast<int>(t.size());
    std::unordered_map<char, int> hash_map;
    for (int i = 0; i < l2; ++i) {
      auto it = hash_map.find(t.at(i));
      if (it == hash_map.end()) { 
        hash_map.insert(std::make_pair(t.at(i), 1));
      } else {
        (*it).second += 1;
      }
    }
    int l = 0;
    int r = 0;
    int left_num = l2;
    int ansl, ansr;
    int min_len = -1;
    while (r < l1 || left_num == 0) {
      if (r < l1 && left_num > 0) {
        ++r;
        auto it = hash_map.find(s.at(r - 1));
        if (it != hash_map.end()) {
          left_num = (*it).second > 0 ? left_num - 1 : left_num;
          (*it).second = (*it).second - 1;
        }
        if (left_num == 0 && (min_len == -1 || (r - l) < min_len)) {
         min_len = r - l;
         ansl = l;
         ansr = r;
        }
      } else {
        auto it = hash_map.find(s.at(l));
        if (it != hash_map.end()) {
          (*it).second = (*it).second + 1;
          left_num = (*it).second <= 0 ? left_num : left_num + 1;
        }
        ++l;
        if (left_num == 0 && (min_len == -1 || (r - l) < min_len)) {
          min_len = r - l;
          ansl = l;
          ansr = r;
        }
      }
    }
    std::string ans = min_len == -1 ? "" : s.substr(ansl, min_len);
    return ans;
  }
};
