// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols - 1;

        while (i < rows && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }

            if (target < matrix[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
