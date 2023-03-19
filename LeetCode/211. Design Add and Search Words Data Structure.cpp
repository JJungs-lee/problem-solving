class TrieNode {
public:
	TrieNode* children[26];
	bool is_word;

	TrieNode() {
		memset(children, 0, sizeof(children));
		is_word = false;
	}
};

class WordDictionary {
private:
	TrieNode* root;

public:
	WordDictionary() {
		root = new TrieNode();
	}

	void addWord(string word) {
		TrieNode* cur = root;

		for (char c : word) {
			int idx = c - 'a';

			if (!cur->children[idx])
				cur->children[idx] = new TrieNode();
			cur = cur->children[idx];
		}
		cur->is_word = true;
	}

	bool search(string word) {
		return dfs(root, word, 0);
	}

	bool dfs(TrieNode* cur, string& word, int idx) {
		if (word.size() == idx)
			return cur->is_word;

		char c = word[idx];
		if (c == '.') {
			for (int i = 0; i < 26; ++i) {
				if (cur->children[i] && dfs(cur->children[i], word, idx + 1))
					return true;
			}
			return false;
		} else {
			if (!cur->children[c - 'a'])
				return false;
			else
				return cur->children[c - 'a'] && dfs(cur->children[c - 'a'], word, idx + 1);
		}
		return false;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */