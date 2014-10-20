// https://oj.leetcode.com/problems/search-insert-position/

class Solution {
public:
	int searchInsert(int a[], int n, int target) {
		int start = 0, end = n - 1;

		while (start <= end) {
			int mid = (end - start) / 2 + start;
			if (a[mid] == target) {
				return mid;
			}

			if (a[mid] < target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		return start;
	}
};
