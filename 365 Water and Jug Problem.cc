class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int g = gcd(x, y);
        if (g == 0) {
            return z == x || z == y;
        }
        return z <= (x + y) && z % g == 0;
    }

private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};
