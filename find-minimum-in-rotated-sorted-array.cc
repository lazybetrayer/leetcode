// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
#include <iostream>

using namespace std;

// ^
// |         o
// |        o
// |       o
// |      o
// |
// |             o
// |            o
// |           o
// +-------------------->
class Solution {
public:
    int findMin(const vector<int> &a, int start, int end) {
        while (start < end) {
            int mid = (end - start) / 2 + start;

            // 递增序列
            if (a[start] < a[end]) {
                return a[start];
            }

            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else if (a[mid] <= a[end]) {
                end = mid;
            }
        }

        return a[start];
    }

    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }
};

int main(int argc, char const* argv[])
{
    vector<int> v{4, 5, 6, 7, 0, 2, 3};

    Solution s;
    cout << s.findMin(v) << endl;
    return 0;
}
