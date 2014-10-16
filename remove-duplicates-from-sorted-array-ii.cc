// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) { return 0; }

		int k = 0;
		int i = k + 1;
		int curr_count = 1;

		while (i < n) {
			if (a[i] == a[k]) {
				if (++curr_count <= 2) {
					a[++k] = a[i];
				}
			} else {
				a[++k] = a[i];
				curr_count = 1;
			}
			i++;
		}

		return k+1;
	}
};
