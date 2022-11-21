class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int ret = 0;
		stack<long> s;

		for (auto const c : tokens) {
			if (c == "+" || c == "-" || c == "*" || c == "/") {
				long second = s.top();
				s.pop();
				long first = s.top();
				s.pop();

				if (c == "+") {
					s.push(first + second);
				} else if (c == "-") {
					s.push(first - second);
				} else if (c == "*") {
					s.push(first * second);
				} else if (c == "/") {
					s.push(first / second);
				}
			} else {
				s.push(stoi(c));
			}
		}
		return s.top();
	}
};