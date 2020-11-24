#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define A_TO_Z 26
struct Trie {
	bool is_finish;
	Trie* next[26];
	
	Trie() : is_finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for(int i = 0; i < 26; ++i)
			if (next[i])
				delete next[i];
	}
	
	void insert(const char* key) {
		// cout << key << endl;
		// cout << *key << endl;
		if (*key == '\0') {
			is_finish = true;
		} else {
			int cur = *key - 'a';
			// cout << cur<<endl;
			if (next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}
	int find(const char* key) {
		// cout << key<< endl;
		// cout << *key <<endl;
		if(is_finish && *key == '\0') 
			return 1;
		int cur = *key -'a';

		if(next[cur] == NULL) 
			return 0;
			
		return next[cur]->find(key +1);
	}
};

int main() {
	// your code goes here
	int n, m;
	int sum = 0;
	cin >> n >> m;
	Trie *root = new Trie;
	
	for (int i = 0; i < n; ++i) {
		char str[501];
		cin >> str;
		root->insert(str);
	}
	for (int i = 0; i < m; ++i) { 
		char str[501];
		cin >> str;
		sum += root->find(str);
	}
	cout <<sum<<endl;
	return 0;
}