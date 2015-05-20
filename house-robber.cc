// https://leetcode.com/problems/house-robber/

#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		// dp[i]抢劫前i个房间能获得最多的钱
		// dp[0] = 0
		// dp[1] = nums[0]
		// dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])

		if (nums.empty()) {
			return 0;
		}

		int a = 0, b = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			int tmp = b;
			b = max(b, a + nums[i]);
			a = tmp;
		}
		return b;
	}
};
