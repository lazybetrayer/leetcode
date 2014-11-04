// https://oj.leetcode.com/problems/word-ladder/

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

// https://github.com/haoel/leetcode/blob/master/src/wordLadder/wordLadder.cpp
// http://www.programcreek.com/2012/12/leetcode-word-ladder/
class Solution {
public:
	int ladderLength(const string &start, const string &end, unordered_set<string> &dict) {
		if (dict.empty()) return 0;

		// 将dict看做一个图, 顶点是每一个字符串，如果两个字符串只相差一个字符，那么这两个顶点之间有一条边
		// BFS广度优先遍历，访问一个顶点时将其从dict中删除，这样不需要额外的空间来记录是否访问过
		queue<string> q;
		int size = dict.begin()->size();
		int len = 1; // 当前节点的距离
		int curr_num = 1; // 当前层节点数
		int next_num = 0; // 记录下一层节点数

		q.push(start);
		dict.erase(start);

		while (!q.empty()) {
			string s = q.front();
			q.pop();

			for (int i = 0; i < size; i++) {
				string t = s;
				for (char c = 'a'; c <= 'z'; c++) {
					t[i] = c;

					if (t == end) {
						return len + 1; // 当前距离加上end
					}

					if (dict.find(t) != dict.end()) {
						dict.erase(t);
						q.push(t);
						++next_num;
					}
				}
			}

			if (--curr_num == 0) {
				++len;
				curr_num = next_num;
				next_num = 0;
			}
		}
		return 0;
	}
};

struct test_case {
	string start;
	string end;
	unordered_set<string> dict;
};

int main(int argc, char const* argv[])
{
	test_case tests[] = {
		{ "hot", "dog", {"hot","dog"}, },
		{ "hit", "cog", { "hot","dot","dog","lot","log" }, },
		{"dod", "cat", {"dot", "cat", "cod", "cot"} },
		{ "a", "c", {"a", "b", "c"}},
		{"nape", "mild", {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"}},
	};
	Solution s;

	for (auto &t : tests) {
		cout << s.ladderLength(t.start, t.end, t.dict) << endl;
	}
	return 0;
}

