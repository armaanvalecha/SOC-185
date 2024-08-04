#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int m = grid.size() - 1; m >= 0; m--) {
            for (int n = grid[m].size() - 1; n >= 0; n--) {
                if (grid[m][n] < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        { -1, -1, -2, -3}
    };
    int result = solution.countNegatives(grid);
    cout << "Number of negative numbers: " << result << endl;
    return 0;
}
