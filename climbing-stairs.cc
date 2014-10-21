// https://oj.leetcode.com/problems/climbing-stairs/

// f(0)=0
// f(1)=1
// f(2)=2
// f(n)=f(n-1)+f(n-2)
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;

		int a = 1, b = 2;

		for (int i = 3; i <= n; i++) {
			int c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
};
