// https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
	int search(int a[], int start, int end, int target) {
		while (start <= end) {
			int mid = (end - start) / 2 + start;

			if (a[mid] == target) {
				return mid;
			}

			if (a[mid] >= a[start]) {
				if (target >= a[start] && target < a[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			} else if (a[mid] <= a[end]) {
				if (target > a[mid] && target <= a[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			}
		}

		return -1;
	}

	int search(int a[], int n, int target) {
		return search(a, 0, n - 1, target);
	}
};
