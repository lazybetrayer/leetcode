//https://oj.leetcode.com/problems/interleaving-string/

#include <iostream>
#include <string>

using namespace std;

bool isInterleave(string s1, string::size_type i, string s2, string::size_type j, string s3, string::size_type k) {
	bool result = false;

	if (k == s3.size()) {
		return i == s1.size() && j == s2.size();
	}

	if (i < s1.size() && s3[k] == s1[i]) {
		result = isInterleave(s1, i + 1, s2, j, s3, k + 1);
	}

	if (result) return true;

	if (j < s2.size() && s3[k] == s2[j]) {
		return isInterleave(s1, i, s2, j + 1, s3, k + 1);
	}

	return false;
}

bool isInterleave(string s1, string s2, string s3) {
	return isInterleave(s1, 0, s2, 0, s3, 0);
}

int main(int argc, char const* argv[])
{
	string s1 = "ab";
	string s2 =  "ba";

	string s[] = {"baab" };

	for (auto ss : s) {
		cout << "len(s1)=" << s1.size() << " " << "len(s2)" << s2.size() << endl;
		cout << ss << " :" << isInterleave(s1, s2, ss) << endl;
	}

	return 0;
}
