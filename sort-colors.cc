// https://oj.leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(int a[], int n) {
		// [0, i)     0
		// [i, k)     1
		// [k, j]     unknown
		// (j, n-1]   2
		// 初始：i=k=0, j=n-1
		int i = 0, k = 0, j = n - 1;

		while (k <= j) {
			if (a[k] == 0) {
				swap(a[k], a[i]);
				k++; i++;
			} else if (a[k] == 1) {
				k++;
			} else { // a[k] == 2
				swap(a[k], a[j]);
				j--;
			}
		}
    }
};
