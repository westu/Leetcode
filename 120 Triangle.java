public class Solution {
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle.size() == 0 || triangle.get(0).size() == 0) {
            return 0;
        }
        ArrayList<Integer> values = new ArrayList<Integer>();
        values.add(triangle.get(0).get(0));
        for (int i = 1; i < triangle.size(); ++i) {
            ArrayList<Integer> tmpValues = new ArrayList<Integer>();
            tmpValues.add(values.get(0) + triangle.get(i).get(0));
            for (int j = 1; j < triangle.get(i).size() - 1; ++j) {
                tmpValues.add(Math.min(values.get(j - 1), values.get(j))
                    + triangle.get(i).get(j));
            }
            tmpValues.add(values.get(triangle.get(i).size() - 2)
                + triangle.get(i).get(triangle.get(i).size() - 1));
            values = tmpValues;
        }
        Integer ans = new Integer(values.get(0));
        for (int i = 1; i < values.size(); ++i) {
            if (values.get(i) < ans) {
                ans = values.get(i);
            }
        }
        return ans;
    }
}
