// https://oj.leetcode.com/problems/minimum-path-sum/


// dp[i][j]为从左上角到grid[i][j]的最小值
// dp[0][0]=grid[0][0]
// dp[0][j]=dp[0][j-1]+grid[0][j]
// dp[i][0]=dp[i-1][0]+grid[i][0]
// dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
// dp[m-1][n-1]即为结果
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		int n = grid[0].size();
#if 1
		int dp[n];

		dp[0] = grid[0][0];

		for (int j = 1; j < n; j++) {
			dp[j] = dp[j-1] + grid[0][j];
		}

		for (int i = 1; i < m; i++) {
			dp[0] = dp[0] + grid[i][0];
			for (int j = 1; j < n; j++) {
				dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
			}
		}

		return dp[n-1];
#else
		vector<vector<int> > dp(m, vector<int>(n));

		dp[0][0] = grid[0][0];

		for (int i = 1; i < m; i++) {
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for (int j = 1; j < n; j++) {
			dp[0][j] = dp[0][j-1] + grid[0][j];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[m-1][n-1];
#endif
	}

};
