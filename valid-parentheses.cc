// https://oj.leetcode.com/problems/valid-parentheses/

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;

		for (string::iterator it = s.begin(); it != s.end(); ++it) {
			switch(*it) {
			case '(': case '[': case '{':
				stk.push(*it);
				break;
			case ')':
				if (stk.empty() || stk.top() != '(') {
					return false;
				}
				stk.pop();
				break;
			case ']':
				if (stk.empty() || stk.top() != '[') {
					return false;
				}
				stk.pop();
				break;
			case '}':
				if (stk.empty() || stk.top() != '{') {
					return false;
				}
				stk.pop();
				break;
			}
		}

		return stk.empty();
	}
};
