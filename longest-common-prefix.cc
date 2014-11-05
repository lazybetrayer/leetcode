// https://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        string::size_type i;

        for (i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            string::size_type k;

            for (k = 1; k < strs.size(); k++) {
                if (strs[k][i] != c) {
                    break;
                }
            }
            if (k < strs.size()) {
                break;
            }
        }

        return strs[0].substr(0, i);
    }
};
