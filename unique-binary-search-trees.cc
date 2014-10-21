// https://oj.leetcode.com/problems/unique-binary-search-trees/

#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
#if 1
		// dp[i]  1...i可以构成的BST的数量
		// dp[0] = 1
		// dp[1] = 1
		// dp[i]=∑dp[k-1]*dp[i-k]  1 <= k <= i
		// dp[n]即为所求
		vector<int> dp(n+1);

		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			for (int k = 1; k <= i; k++) {
				dp[i] += dp[k-1] * dp[i-k];
			}
		}

		return dp[n];
#else
		if (n <= 1) return 1;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			count += numTrees(i-1) * numTrees(n-i);
		}
		return count;
#endif
	}
};
