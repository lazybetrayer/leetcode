// https://oj.leetcode.com/problems/maximum-subarray/

// s[n]: 以a[n]结尾的子数组的最大和
// s[0] = a[0]
// s[n] = max{s[n-1]+a[n], a[n]}
int maxSubArray(int a[], int n)
{
	int max_sum = a[0];
	int sum = a[0];

	for (int i = 1; i < n; i++) {
		sum = max(sum + a[i], a[i]);

		if (sum > max_sum) {
			max_sum = sum;
		}
	}

	return max_sum;
}
