// https://leetcode.com/problems/house-robber-ii/

#include <vector>

using namespace std;

class Solution {
public:
	// https://leetcode.com/problems/house-robber/
	int rob(vector<int>& nums, int start, int end) {
		if (start > end) {
			return 0;
		}

		int a = 0, b = nums[start];

		for (int i = start+1; i <= end; i++) {
			int tmp = b;
			b = max(b, a + nums[i]);
			a = tmp;
		}
		return b;
	}

	int rob(vector<int>& nums) {
		int size = nums.size();

		if (size == 0) return 0;
		if (size == 1) return nums[0];
		if (size == 2) return max(nums[0], nums[1]);

		return max(rob(nums, 0, size-2), rob(nums, 1, size-1));
	}
};
