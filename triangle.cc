// https://oj.leetcode.com/problems/triangle/

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
#if 1
		// http://fisherlei.blogspot.com/2013/01/leetcode-triangle.html
		// 从下往上
		// dp[n-1][j] = triangle[n-1][j]
		// dp[i][j] = min{dp[i+1][j+1], dp[i+1][j]} + triangle[i][j]
		// dp[0][0]为所求
        int n = triangle.size();
        vector<int> dp(n);

		for (int j = 0; j < n; j++) {
			dp[j] = triangle[n-1][j];
		}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
			}
		}

		return dp[0];
#else
#if 1
        int n = triangle.size();
        vector<int> dp(n);

        dp[0] = triangle[0][0];
        int saved = dp[0]; // 保存dp[i-1][j-1]的值
        for (int i = 1; i < n; i++) {
#if 1
			// 从后往前，就不需要保存dp[i-1][j-1]的值了
			for (int j = i; j >= 0; j--) {
				if (j == 0) {
					dp[j] += triangle[i][j];
				} else if (j == i) {
					dp[j] = dp[j-1] + triangle[i][j];
				} else {
					dp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
				}
			}
#else
			for (int j = 0; j <= i; j++) {
				int tmp = dp[j];
				if (j == 0) {
					dp[j] += triangle[i][j];
				} else if (j == i) {
					dp[j] = saved + triangle[i][j];
				} else {
					dp[j] = triangle[i][j] + min(dp[j], saved);
				}
				saved = tmp;
			}
#endif
		}

		int res = dp[0];
		for (int i = 1; i < n; i++) {
			res = min(res, dp[i]);
		}
		return res;
#else
		// dp[i][j]到triangle[i][j]的minimum path
		// dp[0][0] = triangle[0][0]
		// dp[i][0] = dp[i-1][0] + triangle[i][0] (i > 0 && j == 0)
		// dp[i][i] = dp[i-1][i-1] + triangle[i][i] (i > 0 && j == i)
		// dp[i][j] = min{dp[i-1][j], dp[i-1][j-1]} + triangle[i][j]
		int n = triangle.size();
		vector<vector<int> > dp(n, vector<int>(n));

		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][j] = triangle[i][j];
				if (j == 0) {
					dp[i][j] += dp[i-1][j];
				} else if (j == i) {
					dp[i][j] += dp[i-1][j-1];
				} else {
					dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
				}
			}
		}

		int res = dp[n-1][0];
		for (int i = 1; i < n; i++) {
			res = min(res, dp[n-1][i]);
		}
		return res;
#endif
#endif
	}
};
