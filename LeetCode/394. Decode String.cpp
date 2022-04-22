class Solution {
public:
	string decodeString(string s) {
		stack<string> letters;
		string num, letter, res;

		for (const char& c : s) {
			if (isdigit(c)) {
				num += c;
				if (letter.length()) {
					letters.push(letter);
					letter.clear();
				}
			} else if (c == '[') {
				if (num.length()) {
					letters.push(num);
					num.clear();
				}
				letters.push("[");
			} else if (isalpha(c)) {
				letter += c;
			} else if (c == ']') {
				letters.push(letter);
				letter.clear();

				string make_letter;
				while (letters.top() != "[") {
					make_letter = letters.top() + make_letter;
					letters.pop();
				}
				// delete "[" word
				letters.pop();

				string repeat_str;
				for (int i = 0; i < stoi(letters.top(), nullptr, 10); ++i)
					repeat_str += make_letter;

				letters.pop();
				letters.push(repeat_str);
			}
		}
		while (!letters.empty()) {
			res = letters.top() + res;
			letters.pop();
		}
		return res + letter;
	}
};