// https://oj.leetcode.com/problems/interleaving-string/
// http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp[i][j]为true表示s3[0..i+j-1] is interleave of s1[0..i-1] and s2[0..j-1]
//
// dp[0][0] = true (s1 and s2 are empty)
// dp[0][j] = (s3[j-1]==s2[j-1] && dp[0][j-1]) (when s1 is empty, s2, s3最后一个字符相同且s2[0..j-2]和s3[0..j-2]相同)
// dp[i][0] = (s3[i-1]==s1[i-1] && dp[i-1][0]) (when s2 is empty)
// dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1]) || (dp[i-1][j] && s1[i-1]==s3[i+j-1]) 看s3的最后一个字符和s1,s2最后一个字符哪个相同

class Solution {
	typedef string::size_type size_type;
public:
	bool isInterleave(const string &s1, const string &s2, const string &s3) {
#if 1
		// O(m*n) time, O(n) space
		int m = s1.size();
		int n = s2.size();

		if (s3.size() != m + n) { return false; }

		vector<bool> dp(n+1);
		dp[0] = true;
		for (int j = 1; j <= n; j++) {
			dp[j] = dp[j-1] && s3[j-1] == s2[j-1]; // dp[0][j]
		}
		for (int i = 1; i <= m; i++) {
			dp[0] = dp[0] && s3[i-1] == s1[i-1]; // dp[i][0]
			for (int j = 1; j <= n; j++) {
				dp[j] = (s3[i+j-1] == s1[i-1] && dp[j]) || (s3[i+j-1] == s2[j-1] && dp[j-1]);
			}
		}
		return dp[n];
#else
		size_type m = s1.size();
		size_type n = s2.size();

		if (m + n != s3.size()) {
			return false;
		}

		vector<vector<bool> > dp(m+1, vector<bool>(n+1));

		dp[0][0] = true;

		for (size_type i = 1; i <= m; i++) {
			dp[i][0] = (s3[i-1] == s1[i-1]) && dp[i-1][0];
		}

		for (size_type j = 1; j <= n; j++) {
			dp[0][j] = (s3[j-1] == s2[j-1]) && dp[0][j-1];
		}

		for (size_type i = 1; i <= m; i++) {
			for (size_type j = 1; j <= n; j++) {
				dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1]))
					|| (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
			}
		}

		return dp[m][n];
#endif
	}
};

int main(int argc, char const* argv[])
{
	string s1 = "a";
	string s2 = "b";
	string s3 = "ab";

	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;

	return 0;
}
