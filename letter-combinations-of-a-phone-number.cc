//https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string char_map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string digits, string::size_type n, string &s, vector<string> &v)
{
	if (n == digits.size()) {
		v.push_back(s);
		return;
	}

	string chars = char_map[digits[n] - '0'];
	for (string::size_type i = 0; i < chars.size(); i++) {
		s += chars[i];
		letterCombinations(digits, n + 1, s, v);
		s.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> v;
	string s;
	letterCombinations(digits, 0, s, v);
	return v;
}

int main(int argc, char const* argv[])
{
	vector<string> v = letterCombinations("23");

	for (auto s: v) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
