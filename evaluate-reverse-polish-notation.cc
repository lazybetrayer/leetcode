// https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens) {
	stack<int> stk;
	for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
		if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();

			int res;

			if (*it == "+") {
				res = a + b;
			} else if (*it == "-") {
				res = b - a;
			} else if (*it == "*") {
				res = a * b;
			} else if (*it == "/") {
				res = b / a;
			}

			stk.push(res);
		} else {
			stk.push(atoi(it->c_str()));
		}
	}

	return stk.top();
}
