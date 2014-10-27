// https://oj.leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

		// 从后往前merge
		while (i >= 0 && j >= 0) {
			if (A[i] >= B[j]) {
				A[k--] = A[i--];
			} else {
				A[k--] = B[j--];
			}
		}

		//while (i >= 0) {
		//    A[k--] = B[i--];
		//}
		while (j >= 0) {
			A[k--] = B[j--];
		}
    }
};

int main(int argc, char const* argv[])
{
	Solution s;
	int a[2] = {1};
	int b[] = {2};
	s.merge(a, 1, b, 1);

	for (auto n : a)
		cout << n << " ";
	cout << endl;

	return 0;
}
