// https://oj.leetcode.com/problems/edit-distance/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		// dp[i][j]为word1[0...i-1](长度为i)和word2[0...j-1](长度为j)的编辑距离
		// dp[0][0]=0
		// dp[i][0]=i
		// dp[0][j]=j
		// dp[i][j] = dp[i-1][j-1] if word1[i-1]==word2[j-1]
		//		min {
		//			dp[i-1][j] + 1, // word1[0...i-2]->word2[0...j-1]再添加word1[i-1]
		//			dp[i][j-1] + 1, // word1[0...i-1]->word2[0...j-2]再添加word2[j-1]
		//			dp[i-1][j-1] + 1, // word1[0...i-2]->word2[0...j-2]再把word1[i-1]替换为word2[j-1]
		//		}
		// dp[m][n]即为所求
#if 1
		vector<int> dp(n + 1);

		for (int j = 0; j <= n; j++) {
			dp[j] = j;
		}

		int saved; // 保存dp[i-1[j-1]

		for (int i = 1; i <= m; i++) {
		    saved = dp[0];
			dp[0] = i;
			for (int j = 1; j <= n; j++) {
				int tmp = dp[j];

				if (word1[i-1] == word2[j-1]) {
					dp[j] = saved;
				} else {
					dp[j] = 1 + min(min(dp[j], dp[j-1]), saved);
				}

				saved = tmp;
			}
		}

		return dp[n];
#else
		vector<vector<int> > dp(m + 1, vector<int>(n + 1));

		for (int i = 0; i <= m; i++) {
			dp[i][0]=i;
		}
		for (int j = 1; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
				}
			}
		}
		return dp[m][n];
#endif
	}
};

int main(int argc, char const* argv[])
{
	string a = "a";
	string b = "a";

	Solution s;
	cout << s.minDistance(a, b) << endl;
	return 0;
}
