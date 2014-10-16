// https://oj.leetcode.com/problems/maximum-product-subarray/

// m[i]以a[i]结尾的字数组乘积最小值
// M[i]以a[i]结尾的字数组乘积最大值
//
// m[0]=M[0]=a[0]
// m[i+1]=min(m[i-1]*a[i], M[i-1]*a[i], a[i])
// M[i+1]=max(m[i-1]*a[i], M[i-1]*a[i], a[i])

class Solution {
public:
	int maxProduct(int a[], int n) {
		int m, M, res;

		m = M = res = a[0];

		for (int i = 1; i < n; i++) {
			int k1 = m * a[i];
			int k2 = M * a[i];

			M = max(max(k1, k2), a[i]);
			m = min(min(k1, k2), a[i]);

			if (M > res) {
				res = M;
			}
		}

		return res;
	}
};
