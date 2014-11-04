// https://oj.leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
	// http://www.cnblogs.com/ganganloveu/p/3761715.html
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};

int main(int argc, char const* argv[])
{
	Solution s;
	//int a[] = {0};
	//int a[] = {3,2,1};
	int a[] = {1,2,3};
	//int a[] = {1, 2};
	//int a[] = {2, 3, 1, 1, 4};
	//int a[] = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};
	cout << s.jump(a, sizeof(a)/sizeof(*a)) << endl;
	return 0;
}
