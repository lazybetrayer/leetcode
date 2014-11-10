// https://oj.leetcode.com/problems/largest-rectangle-in-histogram/

// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
#if 1
	int largestRectangleArea(vector<int> &height) {
		int size = height.size();
		int max_area = 0;
		int i = 0;
		stack<int> stk;

		// stack记录子问题的开始位置
		// 1. 若栈空，将当前下标入栈
		// 2. 若当前元素大于栈顶下标对应的元素，当前下标入栈
		// 3. 若　....　等于　....　，skip
		// 4. 若　....　小于　....　，以栈顶元素开始的子问题结束，出栈并且计算面积，更新max_area，
		//                            直到栈为空或栈顶下标对应的元素小于等于当前元素
#if 1
		while (i < size) {
			while (!stk.empty() && height[stk.top()] > height[i]) {
				int n = stk.top();
				stk.pop();
				int area = height[n] * (stk.empty() ? i : i-stk.top()-1);
				max_area = max(max_area, area);
			}

			stk.push(i++);
		}

		while (!stk.empty()) {
			int n = stk.top();
			stk.pop();
			int area = height[n] * (stk.empty() ? i : i - stk.top() - 1);
			max_area = max(max_area, area);
		}
#else
		while (i < size) {
			if (stk.empty() || height[stk.top()] <= height[i]) {
				stk.push(i++);
			} else {
				int n = stk.top();
				stk.pop();
				//printf("height[%d]=%d, i=%d\n", n, height[n], i);
				int area = height[n] * (stk.empty() ? i : i - stk.top() - 1);
				max_area = max(max_area, area);
			}
		}

		while (!stk.empty()) {
			int n = stk.top();
			stk.pop();
			int area = height[n] * (stk.empty() ? i : i - stk.top() - 1);
			max_area = max(max_area, area);
		}
#endif
		return max_area;
	}
#else
	int largestRectangleArea(vector<int> &height) {
		stack<pair<int, int>> stk; // value, begin
		int largest = 0;
		int size = height.size();

		for (int i = 0; i < size; i++) {
			if (stk.empty() || height[i] > stk.top().first) {
				stk.push(make_pair(height[i], i));
			} else {
				int begin = i;
				while (!stk.empty() && stk.top().first > height[i]) {
					auto p = stk.top();
					stk.pop();
					begin = p.second;
					largest = max(largest, p.first*(i-p.second));
				}

				if (stk.empty()) {
					stk.push(make_pair(height[i], 0));
				} else if(stk.top().first < height[i]) {
					stk.push(make_pair(height[i], begin));
				}
			}
		}

		while (!stk.empty()) {
			auto p = stk.top();
			stk.pop();
			largest = max(largest, p.first*(size-p.second));
		}

		return largest;
	}
#endif
};

int main(int argc, char const* argv[])
{
	//vector<int> v{2,3,3,3,4};
	vector<int> v{0,0,0};
	Solution s;
	cout << s.largestRectangleArea(v) << endl;
	return 0;
}
