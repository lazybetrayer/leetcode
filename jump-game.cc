// https://oj.leetcode.com/problems/jump-game/

class Solution {
public:
	bool canJump(int a[], int n) {
#if 1
		// 从前往后遍历，记录能够跳到的最远位置k
		// 初始时k=0
		// 对于位置i，如果k<i则无法跳到终点，否则k = max{k, i + a[i]}
		// 最后如果有k >= n - 1则可以跳到终点
		int k = 0;

		for (int i = 0; i < n - 1 && k < n - 1; i++) {
			if (k < i) return false;
			k = max(i + a[i], k);
		}

		return k >= n - 1;
#else
		// 从后往前遍历，如果可以从第i个位置跳到n-1，那么只要看能否跳到i即可
		// 因为如果有k < i并且可以从k跳到n-1，那么必定可以从k跳到i，再跳到n-1
		int target = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (i + a[i] >= target) {
				target = i;
			}
		}
		return target == 0;
#endif
	}
};
