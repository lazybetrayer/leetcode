// https://oj.leetcode.com/problems/pascals-triangle/

#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<int> > v) {
	for (auto &vv : v) {
		for (auto n : vv) {
			cout << n << " ";
		}
		cout << endl;
	}
	cout << "=========" << endl;
}

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;

        for (int i = 1; i <= numRows; i++) {
            vector<int> v;
            v.push_back(1);

            for (int j = 1; j < i - 1; j++) {
				auto vv = res.back();
                v.push_back(vv[j-1] + vv[j]);
            }

            if (i > 1) {
                v.push_back(1);
            }
            res.push_back(v);
        }
        return res;
    }
};

int main(int argc, char const* argv[])
{
	int n = 5;
	Solution s;

	print(s.generate(n));
	return 0;
}
