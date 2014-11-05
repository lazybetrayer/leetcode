// https://oj.leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1);
        v[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            v[i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                v[j] += v[j-1];
            }
        }
        return v;
    }
};

void print(const vector<int> &v) {
	for (auto n : v) {
		cout << n << " ";
	}
	cout << endl;
}

int main(int argc, char const* argv[])
{
	int a[] = {0, 1, 2, 3, 4, 10};
	Solution s;

	for (auto n : a) {
		print(s.getRow(n));
	}
	return 0;
}
