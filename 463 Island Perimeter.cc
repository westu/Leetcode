class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid.at(0).empty()) {
            return 0;
        }
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.at(0).size(); ++j) {
                if (grid.at(i).at(j) == 1) {
                    perimeter += cal_perimeter(grid, i, j);
                }
            }
        }
        return perimeter;
    }

private:
    int cal_perimeter(const vector<vector<int>>& grid, int x, int y) {
        int perimeter = 0;
        for (int i = -1; i <= 1; i += 2) {
            int nx = x + i;
            int ny = y;
            if (nx == -1 || nx == grid.size() || ny == -1 ||
                ny == grid.at(0).size() || grid.at(nx).at(ny) == 0) {
                ++perimeter;
            }
            
            nx = x;
            ny = y + i;
            if (nx == -1 || nx == grid.size() || ny == -1 ||
                ny == grid.at(0).size() || grid.at(nx).at(ny) == 0) {
                ++perimeter;
            }
        }
        return perimeter;
    }
};
