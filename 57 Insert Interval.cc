/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        if (intervals.empty() == true) {
            ans.push_back(newInterval);
            return ans;
        }
        bool newIntervalHasInserted = false;
        for (int i = 0; i < static_cast<int>(intervals.size()); ++i) {
            if (intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                if (newIntervalHasInserted == false) {
                    ans.push_back(newInterval);
                    newIntervalHasInserted = true;
                }
                ans.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (newIntervalHasInserted == false) {
        // in this case newInterval must be the rightest
            ans.push_back(newInterval);
        }
        return ans;
    }
};
