/*
 * Reverse Polish Notation means postfix notation (후위 연산자 표기)
 */
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int ret = 0;
		stack<int> s;

		for (auto const c : tokens) {
			if (c == "+" || c == "-" || c == "*" || c == "/") {
				int second = s.top();
				s.pop();
				int first = s.top();
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