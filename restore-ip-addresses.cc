// https://oj.leetcode.com/problems/restore-ip-addresses/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
#if 1
	void restoreIpAddresses(const string &s, string::size_type k, int part_num, const string &ip, vector<string> &res) {
		if (part_num == 4 && k == s.size()) {
			res.push_back(ip);
			return;
		}

		if (part_num == 4 || k == s.size()) {
			return;
		}

		int n = 0;
		for (string::size_type i = k; i < k + 3 && i < s.size(); i++) {
			n = n * 10 + s[i] - '0';
			if (n > 255) {
				return;
			}

			string t;
			if (part_num == 0) {
				t = s.substr(k, i+1-k);
			} else {
				t = ip + "." + s.substr(k, i+1-k);
			}

			restoreIpAddresses(s, i+1, part_num+1, t, res);

			if (n == 0) {
				return;
			}
		}
	}

	vector<string> restoreIpAddresses(const string &s) {
		vector<string> res;
		string ip;
		restoreIpAddresses(s, 0, 0, ip, res);
		return res;
	}
#else
	string join(const vector<string> &s) {
		string t = s.front();
		for (vector<string>::const_iterator it = s.begin() + 1; it != s.end(); ++it) {
			t += "." + *it;
		}
		return t;
	}

	void restoreIpAddresses(const string &s, string::size_type k, vector<string> &ip, vector<string> &res) {
		if (ip.size() == 4 && k == s.size()) {
			res.push_back(join(ip));
			return;
		}

		if (ip.size() == 4 || k == s.size()) {
			return;
		}

		int n = 0;
		for (string::size_type i = k; i < k + 3 && i < s.size(); i++) {
			n = n * 10 + s[i] - '0';
			if (n > 255) {
				return;
			}
			ip.push_back(s.substr(k, i-k+1));
			restoreIpAddresses(s, i+1, ip, res);
			ip.pop_back();

			//if (k == i && s[k] == '0') {
			if (n == 0) {
				return;
			}
		}
	}
	vector<string> restoreIpAddresses(const string &s) {
		vector<string> res;
		vector<string> ip;
		restoreIpAddresses(s, 0, ip, res);
		return res;
	}
#endif
};

int main(int argc, char const* argv[])
{
	Solution s;

	for (auto &t : {"0000", "1111", "255255255255", "255256255255", "010010"}) {
		auto v = s.restoreIpAddresses(t);

		for (auto &s : v) {
			cout << s << endl;
		}
		cout << "===========" << endl;
	}
	return 0;
}
