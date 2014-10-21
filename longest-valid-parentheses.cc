// https://oj.leetcode.com/problems/longest-valid-parentheses/

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
#if 1
		// http://fisherlei.blogspot.com/2013/03/leetcode-longest-valid-parentheses.html
		stack<int> stk;
		int longest = 0;

		for (string::size_type i = 0; i < s.size(); i++) {
			if (s[i] == '(' || stk.empty() || s[stk.top()] == ')') {
				stk.push(i);
			} else {
				stk.pop();

                int len = stk.empty() ? i + 1 : i - stk.top();
				longest = max(longest, len);
			}
		}

		return longest;
#else
		vector<int> dp(s.size() + 1);
		stack<int> stk;
		int longest = 0;

		for (string::size_type i = 0; i < s.size(); i++) {
			if (s[i] == '(' || stk.empty() || s[stk.top()] == ')') {
				dp[i] = 0;
				stk.push(i);
			} else {
				int k = stk.top();
				stk.pop();
				dp[i] = i - k + 1;
				if (k - 1 >= 0) {
					dp[i] += dp[k-1];
				}
				if (dp[i] > longest) {
					longest = dp[i];
				}
			}
		}

		return longest;
#endif
	}
};
