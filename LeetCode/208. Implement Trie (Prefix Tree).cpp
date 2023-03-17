class TrieNode {
public:
	bool isWord;
	TrieNode* children[26];

	TrieNode() {
		isWord = false;
		memset(children, 0, sizeof(children));
	}
};

class Trie {
private:
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* temp = root;

		for (char c : word) {
			int idx = c - 'a';
			if (!temp->children[idx])
				temp->children[idx] = new TrieNode();
			temp = temp->children[idx];
		}
		temp->isWord = true;
	}

	bool search(string word) {
		TrieNode* temp = root;

		for (char c : word) {
			int idx = c - 'a';
			if (!temp->children[idx])
				return false;
			temp = temp->children[idx];
		}
		return temp->isWord;
	}

	bool startsWith(string prefix) {
		TrieNode* temp = root;

		for (char c : prefix) {
			int idx = c - 'a';
			if (!temp->children[idx])
				return false;
			temp = temp->children[idx];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */