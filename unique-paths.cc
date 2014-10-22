// https://oj.leetcode.com/problems/unique-paths/

class Solution {
public:
	int uniquePaths(int m, int n) {
#if 1
		vector<int> dp(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[j] += dp[j-1];
			}
		}
		return dp[n-1];
#else
		// dp[i][j]到(i, j)格的路径数
		// dp[i][j]=1 if i == 0 or j == 0
		// dp[i][j]=dp[i-1][j]+dp[i][j-1]
		vector<vector<int> > dp(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				} else {
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}

			}
		}
		return dp[m-1][n-1];
#endif
	}
};
