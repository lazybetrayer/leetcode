// https://oj.leetcode.com/problems/add-binary/

class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		int i = a.size() - 1, j = b.size() - 1;
		string res;

		while (i >= 0 || j >= 0 || carry > 0) {
			int n = carry;
			if (i >= 0) { n += a[i] - '0'; }
			if (j >= 0) { n += b[j] - '0'; }

			res = (n % 2 == 0 ? "0" : "1") + res;
			carry = n / 2;

			if (i >= 0) { i--; }
			if (j >= 0) { j--; }
		}
		return res;
	}
};
