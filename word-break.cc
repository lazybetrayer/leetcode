// https://oj.leetcode.com/problems/word-break/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(const string &s, unordered_set<string> &dict) {
#if 1
        if (dict.empty()) return false;
		// dp[i] 代表字符串s[0..i]是否能被分解
		// dp[i] = true     if s[0..i]在dict中
		//		 = true     if 存在k (k >= 0 && k < i)使得dp[k]=true && s[k+1..i]在dict中
		//		 = false    else
		int n = s.size();
		vector<int> dp(n);

		for (int i = 0; i < n; i++) {
			dp[i] = dict.find(s.substr(0, i+1)) != dict.end();

			for (int k = 0; k < i && !dp[i]; k++) {
				dp[i] = dp[k] && dict.find(s.substr(k+1, i-k)) != dict.end();
			}
		}

		return dp[n-1];
#else
        if (dict.empty()) return false;
        // dp[i][j] (j >= i) 代表字符串s[i..j]是否能被分成一系列在字典中的单词
        // dp[i][j] = true   s[i..j]在字典中
        //     或   = dp[i][k] && dp[k+1][j]  for all k >=i && k < j
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                int j = i + len - 1;
                auto sub = s.substr(i, len);
                dp[i][j] = dict.find(sub) != dict.end();

                for (int k = i; !dp[i][j] && k <= j; k++) {
                    dp[i][j] = dp[i][j] || (dp[i][k] && dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
#endif
    }
};

int main(int argc, char const* argv[])
{
	string s = "bb";
	unordered_set<string> dict{"a","b","bbb","bbbb"};
	Solution solution;

	cout << solution.wordBreak(s, dict) << endl;
	return 0;
}
