// https://oj.leetcode.com/problems/unique-paths-ii/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
			return 0;
		}
		// dp[0][0]=1
		// dp[i][j] = 0			if obstaclegrid[i][j]==1
		//			= dp[i-1][j]+dp[i][j-1]
		vector<int> dp(n);
		dp[0] = 1;
		for (int i = 0; i < m; i++) {
			//if (obstacleGrid[i][j] == 1) {
			//    dp[0] = 0;
			//}

			for (int j = 0; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[j] = 0;
				} else if (j > 0) {
					dp[j] += dp[j-1];
				}
			}
		}
		return dp[n-1];
    }
};
