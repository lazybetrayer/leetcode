// https://oj.leetcode.com/problems/generate-parentheses.cc

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 3 "((()))", "(()())", "(())()", "()(())", "()()()"
class Solution {
public:
#if 1
	// l, r分别记录剩余的'(', ')'数量
	void generateParenthesis(int l, int r, string &s, vector<string> &v) {
		if (r == 0) {
			v.push_back(s);
			return;
		}

		if (l > 0) {
			s.push_back('(');
			generateParenthesis(l - 1, r, s, v);
			s.pop_back();
		}

		// 剩余'('数量小于')'
		if (l < r) {
			s.push_back(')');
			generateParenthesis(l, r - 1, s, v);
			s.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		string s;
		generateParenthesis(n, n, s, v);
		return v;
	}
#else
	// l记录'('的数量
	// r记录')'的数量
	void generateParenthesis(int n, int l, int r, string &s, vector<string> &v) {
		if (r == n) {
			v.push_back(s);
			return;
		}

		// 可以放'('
		if (l < n) {
			s.push_back('(');
			generateParenthesis(n, l + 1, r, s, v);
			s.pop_back();
		}

		// '('的数量大于')'，可以放')'
		if (l > r) {
			s.push_back(')');
			generateParenthesis(n, l, r + 1, s, v);
			s.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> v;
		string s;
		generateParenthesis(n, 0, 0, s, v);
		return v;
	}
#endif
};

int main(int argc, char const* argv[])
{
	Solution s;
	int n = 3;
	for (auto ss : s.generateParenthesis(n)) {
		cout << ss << endl;
	}
	return 0;
}
