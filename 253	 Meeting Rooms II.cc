/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
 public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: the minimum number of conference rooms required
   */
  int minMeetingRooms(vector<Interval> &intervals) {
    map<int, int> record;
    for (auto interval : intervals) {
      ++record[interval.start];
      --record[interval.end];
    }
    int max_num(0), current_num(0);
    for (auto r : record) {
      current_num += r.second;
      max_num = max(max_num, current_num);
    }
    return max_num;
  }
};
