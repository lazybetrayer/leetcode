// https://oj.leetcode.com/problems/two-sum/

class Solution {
	class compare {
		const vector<int> &v;
	public:
		compare(const vector<int> &v):v(v){}
		bool operator()(int i, int j) const {
			return v[i] < v[j];
		}
	};
public:
	vector<int> twoSum(const vector<int> &numbers, int target) {
		vector<int> indexes, res;

		for (int i = 0; i < numbers.size(); i++) {
			indexes.push_back(i);
		}

		sort(indexes.begin(), indexes.end(), compare(numbers));

		int i = 0, j = numbers.size() - 1;

		while (i < j) {
			int sum = numbers[indexes[i]] + numbers[indexes[j]];

			if (sum == target) {
				res.push_back(indexes[i]+1);
				res.push_back(indexes[j]+1);
				sort(res.begin(), res.end());
				break;
			} else if (sum > target) {
				j--;
			} else {
				i++;
			}
		}

		return v;
	}
};
