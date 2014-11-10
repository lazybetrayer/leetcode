// https://oj.leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int start = 0;
		int end = s.size() - 1;

		while (start < end) {
			char a = s[start];
			char b = s[end];

			if (!isalnum(a)) {
				start++;
			} else if (!isalnum(b)) {
				end--;
			} else if (tolower(a) == tolower(b)) {
				start++;
				end--;
			} else {
				return false;
			}
		}

		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	cout << s.isPalindrome("a.b,.") << endl;
	return 0;
}
