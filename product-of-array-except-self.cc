// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int> &v)
{
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
}

class Solution {
public:
    // https://leetcode.com/discuss/46256/c-within-10-lines-o-n-o-1
    vector<int> productExceptSelf(const vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return nums;
        // 1   2   3   4
        //
        // 1   1   2   6
        //
        // 24  12  8   6
        vector<int> res;
        int sz = nums.size();
        int tmp = 1;
        for (auto n : nums) {
            res.push_back(tmp);
            tmp *= n;
        }
        tmp = 1;
        for (int i = sz-1; i >= 0; --i) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v{1, 2, 3, 4};
    auto res = s.productExceptSelf(v);
    print(res);
    return 0;
}
