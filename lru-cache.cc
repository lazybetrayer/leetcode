// https://oj.leetcode.com/problems/lru-cache/

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
	typedef int key_type;
	typedef int value_type;

	typedef pair<key_type, value_type> entry_type;
	typedef list<entry_type> entry_list_type;
	typedef unordered_map<key_type, entry_list_type::iterator> key_index_map_type;

	int capacity;
	key_index_map_type key_index_map;
	entry_list_type entry_list; // 链表按访问时间排序
public:
    LRUCache(int capacity) : capacity(capacity) {}

	void move_to_front(entry_list_type::iterator it) {
		entry_list.splice(entry_list.begin(), entry_list, it);
	}

    int get(int key) {
		key_index_map_type::iterator it = key_index_map.find(key);

		if (it == key_index_map.end()) {
			return -1;
		}

		move_to_front(it->second);

		return it->second->second;
    }

    void set(int key, int value) {
		key_index_map_type::iterator it = key_index_map.find(key);
		if (it != key_index_map.end()) {
			it->second->second = value;
			move_to_front(it->second);
			return;
		}

		if (entry_list.size() >= capacity) {
			// invalidate least recently used item
			entry_type entry = entry_list.back();
			entry_list.pop_back();
			key_index_map.erase(entry.first);
		}

		entry_list.push_front(make_pair(key, value));
		key_index_map.insert(make_pair(key, entry_list.begin()));
    }
};
