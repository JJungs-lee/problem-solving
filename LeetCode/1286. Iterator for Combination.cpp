class CombinationIterator {
	vector<string> v;
	int cur_idx;
	void make_combi(string& s, string combi_s, int idx, int max_len) {
		if (max_len <= combi_s.size()) {
			v.push_back(combi_s);
			return;
		}

		for (int i = idx; i < s.size(); ++i)
			make_combi(s, combi_s + s[i], i + 1, max_len);
	}

public:
	CombinationIterator(string characters, int combinationLength) {
		cur_idx = 0;
		make_combi(characters, "", 0, combinationLength);
	}

	string next() {
		return v[cur_idx++];
	}

	bool hasNext() {
		return cur_idx < v.size();
	}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */