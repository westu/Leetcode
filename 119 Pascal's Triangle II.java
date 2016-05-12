public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> line = new ArrayList<Integer>();
        line.add(1);
        for (int i = 1; i <= rowIndex; ++i) {
            ArrayList<Integer> tmpLine = new ArrayList<Integer>();
            tmpLine.add(1);
            for (int j = 1; j < i; ++j) {
                tmpLine.add(line.get(j - 1) + line.get(j));
            }
            tmpLine.add(1);
            line = tmpLine;
        }
        return line;
    }
}
