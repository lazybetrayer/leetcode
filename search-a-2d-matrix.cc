// https://oj.leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int m = matrix.size();
		int n = matrix[0].size();

		int start = 0, end = m * n - 1;
		while (start <= end) {
			int mid = (end - start) / 2 + start;
			int i = mid / n;
			int j = mid % n;

			if (matrix[i][j] == target) {
				return true;
			}

			if (matrix[i][j] < target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		return false;
	}
};
