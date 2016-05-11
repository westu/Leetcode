public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        if (numRows == 0) {
            return triangle;
        }
        ArrayList<Integer> line = new ArrayList<Integer>();
        line.add(1);
        triangle.add(line);
        for (int i = 2; i <= numRows; ++i) {
            line = new ArrayList<Integer>();
            line.add(1);
            for (int j = 2; j < i; ++j) {
                line.add(triangle.get(i - 2).get(j - 2) +
                         triangle.get(i - 2).get(j - 1));
            }
            line.add(1);
            triangle.add(line);
        }
        return triangle;
    }
}
