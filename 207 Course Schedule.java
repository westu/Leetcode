public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> map = new ArrayList<ArrayList<Integer>>();
        int[] inCount = new int[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            inCount[i] = 0;
            map.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < prerequisites.length; ++i) {
            for (int j = 1; j < prerequisites[i].length; ++j) {
                map.get(prerequisites[i][j]).add(prerequisites[i][0]);
                ++inCount[prerequisites[i][0]];
            }
        }
        Queue<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < numCourses; ++i) {
            if (inCount[i] == 0) {
                queue.add(i);
            }
        }
        int listCourse = 0;
        while (!queue.isEmpty()) {
            int point = queue.poll();
            ++listCourse;
            for (int i : map.get(point)) {
                --inCount[i];
                if (inCount[i] == 0) {
                    queue.add(i);
                }
            }
        }
        return listCourse == numCourses;
    }
}
