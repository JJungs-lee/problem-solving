class MyStack {
	queue<int> q;

public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret;
		queue<int> temp;

		while (q.size() != 1) {
			temp.push(q.front());
			q.pop();
		}
		ret = q.front();
		q = temp;

		return ret;
	}

	/** Get the top element. */
	int top() {
		return q.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */