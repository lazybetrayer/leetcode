// https://oj.leetcode.com/problems/decode-ways/

class Solution {
public:
    bool valid(char c) {
        return c >= '1' && c <= '9';
    }
    bool valid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6');
    }
    int numDecodings(string s) {
        if (s.empty()) return 0;
        // dp[i]表示s前i个字符的decode ways
        // dp[0] = 1
        // dp[1] = 1	valid(s[0])
        //         0	else
        //
        // dp[n] = dp[n-1]			valid(s[i-1]) && !valid(s[i-2], s[i-1])
        //         dp[n-2]			!valid(s[i-1]) && valid(s[i-2], s[i-1])
        //         dp[n-1]+dp[n-2]	valid(s[i-1]) && valid(s[i-2], s[i-1])
        //         0				else
        int a = 1, b = valid(s[0]);

        for (string::size_type i = 2; i <= s.size(); i++) {
            int c = 0;

            if (valid(s[i-1]))
                c += b;
            if (valid(s[i-2], s[i-1]))
                c += a;
            a = b;
            b = c;
        }
        return b;
    }
};
