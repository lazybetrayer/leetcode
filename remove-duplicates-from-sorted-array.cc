// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
	int removeDuplicates(int a[], int n) {
		if (n == 0) { return 0; }

		int k = 0;
		int i = k + 1;

		while (i < n) {
			if (a[i] != a[k]) {
				a[++k] = a[i];
			}
			i++;
		}

		return k+1;
	}
};
