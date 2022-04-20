class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ret;
		vector<string> cur_row;
		int sum_of_words = 0;

		for (const string& word : words) {
			int word_size = word.size();
			int cur_row_size = cur_row.size();

			if (sum_of_words + cur_row_size + word_size > maxWidth) {
				int spaces = maxWidth - sum_of_words;

				if (cur_row_size == 1) {
					while (spaces--)
						cur_row[0] += " ";
				} else {
					for (int i = 0; i < spaces; ++i)
						cur_row[i % (cur_row_size - 1)] += " ";
				}
				ret.push_back(concat(cur_row, ""));
				cur_row.clear();
				sum_of_words = 0;
			}
			sum_of_words += word_size;
			cur_row.push_back(word);
		}
		ret.push_back(leftJust(concat(cur_row, " "), maxWidth));
		return ret;
	}

	string concat(const vector<string>& v, const string& c) {
		string s;
		for (auto it = v.begin(); it != v.end(); ++it) {
			s += *it;
			if (it != v.end() - 1)
				s += c;
		}
		return s;
	}
	string leftJust(string s, int width) {
		for (int i = 0; i < s.size() - width; ++i)
			s += " ";
		return s;
	}
};
