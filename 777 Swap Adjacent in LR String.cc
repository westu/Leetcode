class Solution {
public:
  bool canTransform(string start, string end) {
    int i(0), j(0);
    while (true) {
      while (i < static_cast<int>(start.size()) && start.at(i) == 'X') {
        ++i;
      }
      while (j < static_cast<int>(end.size()) && end.at(j) == 'X') {
        ++j;
      }
      if (i == static_cast<int>(start.size()) || j == static_cast<int>(end.size())) {
        break;
      }
      if (start.at(i) != end.at(j)) {
        return false;
      }
      if (start.at(i) == 'L' && i < j || start.at(i) == 'R' && i > j) {
        return false;
      }
      ++i;
      ++j;
    }
    while (i < static_cast<int>(start.size()) && start.at(i) == 'X') {
      ++i;
    }
    while (j < static_cast<int>(end.size()) && end.at(j) == 'X') {
      ++j;
    }
    return i == static_cast<int>(start.size()) && j == static_cast<int>(end.size());
  }
};
