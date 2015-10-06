// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v{1};
        v.reserve(n);
        int i = 0, j = 0, k = 0;

        while (v.size() < n) {
            int m = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            v.push_back(m);
            if (m == v[i] * 2) i++;
            if (m == v[j] * 3) j++;
            if (m == v[k] * 5) k++;
        }

        return v.back();
    }
};
