/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval& p, const Interval& q) {
    if (p.start != q.start) {
        return p.start < q.start;
    } else {
        return p.end < q.end;
    }
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        if (intervals.empty() == true) {
            return ans;
        }
        int pos = 0;
        int len = static_cast<int>(intervals.size());
        while (pos < len) {
            int s = intervals[pos].start;
            int e = intervals[pos].end;
            while (pos < len && intervals[pos].start <= e) {
                e = max(e, intervals[pos].end);
                ++pos;
            }
            ans.push_back(Interval(s, e));
        }
        return ans;
    }
};
