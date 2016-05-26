/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    /**
     * @param points an array of point
     * @return an integer
     */
    public int maxPoints(Point[] points) {
        if (points == null) {
            return 0;
        }
        if (points.length <= 2) {
            return points.length;
        }
        int maxNum = 0;
        for (int i = 0; i < points.length; ++i) {
            for (int j = i + 1; j < points.length; ++j) {
                if (isSamePoint(points, i, j)) {
                    maxNum = Math.max(maxNum, 3);
                    continue;
                }
                int count = 2;
                for (int k = 0; k < points.length; ++k) {
                    if (i != k && j != k) {
                        int left = (points[k].y - points[i].y) * (points[k].x - points[j].x);
                        int right = (points[k].y - points[j].y) * (points[k].x - points[i].x);
                        if (left == right) {
                            ++count;
                        }
                    }
                }
                maxNum = Math.max(maxNum, count);
            }
        }
        return maxNum;
    }

    private boolean isSamePoint(Point[] points, int x, int y) {
        return points[x].x == points[y].x && points[x].y == points[y].y;
    }
}
