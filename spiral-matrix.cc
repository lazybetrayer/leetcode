// https://oj.leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> v;
		if (matrix.empty()) return v;
		int m = matrix.size() - 1;
		int n = matrix[0].size() - 1;
		int i = 0, j = 0;

		while (i <= m && j <= n) {
			for (int k = j; k <= n; k++) { // 往右
				v.push_back(matrix[i][k]);
			}
			for (int k = i+1; k <= m; k++) { // 往下
				v.push_back(matrix[k][n]);
			}
			if (i < m) { // 往左
				for (int k = n-1; k >= j; k--) {
					v.push_back(matrix[m][k]);
				}
			}
			if (j < n) { // 往上
				for (int k = m-1; k > i; k--) {
					v.push_back(matrix[k][j]);
				}
			}
			i++; j++; m--; n--;
		}

		return v;
	}
};


int main(int argc, char const* argv[])
{
	vector<vector<int>> v{
		{2,3},
		//{1,2,3},
		//{4,5,6},
		//{7,8,9},
	};
	Solution s;

	for (auto n : s.spiralOrder(v)) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}
