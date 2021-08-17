class Solution {
public:
	bool isValid(string s) {
		int len = s.size();
		stack<char> _stack;

		for (int i = 0; i < len; ++i) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				_stack.push(s[i]);
			} else if (_stack.empty()) {
				return false;
			} else {
				if (s[i] == ')' && _stack.top() == '(' ||
				    s[i] == '}' && _stack.top() == '{' ||
				    s[i] == ']' && _stack.top() == '[') {
					_stack.pop();
				} else {
					return false;
				}
			}
		}
		if (_stack.empty()) {
			return true;
		} else {
			return false;
		}
	}
};