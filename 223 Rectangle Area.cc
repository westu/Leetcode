class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum_area = (C - A) * (D - B) + (G - E) * (H - F);
        int max_left = max(A, E);
        int min_right = min(C, G);
        int max_down = max(B, F);
        int min_up = min(D, H);
        if (max_left >= min_right || max_down >= min_up) {
            return sum_area;
        }
        return sum_area - (min_right - max_left) * (min_up - max_down);
    }
};
