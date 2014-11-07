// https://oj.leetcode.com/problems/string-to-integer-atoi/

#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL || *str == '\0') return 0;
        bool negative = false;
        const char *p = str;
        int n = 0;

        while (isspace(*p)) {
            ++p;
        }
        if (*p == '+' || *p == '-') {
            negative = *p == '-';
            ++p;
        }

        while (*p >= '0' && *p <= '9') {
			// INT_MAX: 2147483647, INT_MIN: -2147483648
			if (n > INT_MAX / 10 || (n == INT_MAX / 10 && *p - '0' > INT_MAX % 10)) { // overflow
				return negative ? INT_MIN : INT_MAX;
			}
            n = n * 10 + *p - '0';
            ++p;
        }

        return negative ? -n : n;
    }
};

int main(int argc, char const* argv[])
{
	Solution s;
	const char *t = "    10522545459";

	cout << atoi(t) << endl;
	cout << s.atoi(t) << endl;
	return 0;
}
