public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        for (int i = 0; i < Math.min(v1.length, v2.length); ++i) {
            int x = Integer.parseInt(v1[i]);
            int y = Integer.parseInt(v2[i]);
            if (x > y) {
                return 1;
            } else if (x < y) {
                return -1;
            }
        }
        if (v1.length > v2.length) {
            return compareLeft(v1, v2.length);
        } else if (v1.length < v2.length) {
            return 0 - compareLeft(v2, v1.length);
        } else {
            return 0;
        }
    }

    private int compareLeft(String[] version, int startPos) {
        for (int i = startPos; i < version.length; ++i) {
            if (Integer.parseInt(version[i]) > 0) {
                return 1;
            }
        }
        return 0;
    }
}
