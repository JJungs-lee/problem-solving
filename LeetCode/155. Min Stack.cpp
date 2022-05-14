class MinStack {
	stack<int> order_s;
	stack<int> min_s;

public:
	MinStack() {
	}

	void push(int val) {
		order_s.push(val);
		if (min_s.empty() || min_s.top() >= val)
			min_s.push(val);
	}

	void pop() {
		if (min_s.top() == order_s.top())
			min_s.pop();
		order_s.pop();
	}

	int top() {
		return order_s.top();
	}

	int getMin() {
		return min_s.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */