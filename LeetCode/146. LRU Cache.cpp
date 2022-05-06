class LRUCache {
private:
	struct Node {
		int key, value;
		Node *prev, *next;
		Node() : prev(nullptr), next(nullptr){};
		Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr){};
	};
	unordered_map<int, Node *> hash_table;
	Node *head, *tail;

	void moveToTail(Node *cur) {
		// disconnect
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		// move to tail
		cur->next = tail;
		cur->prev = tail->prev;
		tail->prev->next = cur;
		tail->prev = cur;
	}
	void addToTail(Node *cur) {
		cur->next = tail;
		cur->prev = tail->prev;
		tail->prev->next = cur;
		tail->prev = cur;
	}
	int capa, size;

public:
	LRUCache(int capacity) {
		capa = capacity;
		size = 0;

		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		auto iter = hash_table.find(key);
		if (iter != hash_table.end()) {
			moveToTail(iter->second);
			return iter->second->value;
		}
		return -1;
	}

	void put(int key, int value) {
		auto iter = hash_table.find(key);
		Node *cur = nullptr;
		if (iter != hash_table.end()) {
			iter->second->value = value;
			moveToTail(iter->second);
		} else {
			// overflow capa
			if (size >= capa) {
				Node *del_node = head->next;
				del_node->next->prev = head;
				head->next = del_node->next;
				size--;
				hash_table.erase(del_node->key);
				delete del_node;
			}
			cur = new Node(key, value);
			hash_table.insert({key, cur});
			addToTail(cur);
			size++;
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */